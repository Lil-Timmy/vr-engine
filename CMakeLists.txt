# Version requirements.
cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project constants.
set (PROJECT_NAME vr-engine)

# Project initialization.
project(${PROJECT_NAME} CXX)

# Project files.
file(GLOB_RECURSE PROJECT_INCLUDE ${PROJECT_SOURCE_DIR}/include/*.ixx)
file(GLOB_RECURSE PROJECT_SRC     ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Project compilation.
add_executable(${PROJECT_NAME} ${PROJECT_SRC})

# Project settings.
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_SOURCE_DIR}/bin/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin/Release"
)

# Project linking.
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
)
target_sources(${PROJECT_NAME} PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    ${PROJECT_INCLUDE}
)

# Libraries:

# GLFW.

# OpenXR.
