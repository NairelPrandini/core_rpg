cmake_minimum_required(VERSION 3.10)

# Project name
project(editor)

# Define paths for SFML libraries and headers in the project directory
set(SFML_LIB_DIR "/usr/lib") # Set the correct path for SFML libraries
set(IMGUI_INCLUDE_DIR "./include/imgui")
set(SFML_INCLUDE_DIR "/usr/include/SFML") # Set the correct path for SFML headers

# Definition of SFML libraries
find_library(SFML_GRAPHICS_LIBRARY NAMES sfml-graphics PATHS ${SFML_LIB_DIR})
find_library(SFML_WINDOW_LIBRARY NAMES sfml-window PATHS ${SFML_LIB_DIR})
find_library(SFML_SYSTEM_LIBRARY NAMES sfml-system PATHS ${SFML_LIB_DIR})

# Check if all libraries were found
if(NOT SFML_GRAPHICS_LIBRARY OR NOT SFML_WINDOW_LIBRARY OR NOT SFML_SYSTEM_LIBRARY)
    message(FATAL_ERROR "SFML libraries not found. Please ensure SFML is installed and paths are correct.")
endif()

set(SFML_LIBRARIES ${SFML_GRAPHICS_LIBRARY} ${SFML_WINDOW_LIBRARY} ${SFML_SYSTEM_LIBRARY} pthread dl GL)

# Add the executable and include all .cpp files in src/ and its subfolders
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Include header directories
include_directories(${SFML_INCLUDE_DIR})
include_directories(${IMGUI_INCLUDE_DIR})
include_directories(include)

# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link SFML to the libraries
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

target_compile_options(${PROJECT_NAME} PRIVATE -O3 -march=native -flto)
set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
