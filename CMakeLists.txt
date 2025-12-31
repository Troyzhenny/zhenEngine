cmake_minimum_required(VERSION 3.20)

project(zhenEngine VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(zhenEngine
    source/main.cpp
)

add_library(glad source/glad.c)
target_include_directories(glad PUBLIC third_party/)


find_package(OpenGL REQUIRED)

target_include_directories(zhenEngine PRIVATE
    include/
    third_party/GLFW/
)

# Linking libraries
target_link_libraries(zhenEngine PRIVATE
    glad
    OpenGL::GL
    "${CMAKE_SOURCE_DIR}/third_party/GLFW/glfw3.lib"
)
