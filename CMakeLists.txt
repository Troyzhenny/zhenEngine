cmake_minimum_required(VERSION 4.0.0)

project(zhenEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(GENERATE_COMPILE_COMMANDS ON)

add_executable(zhenEngine
    source/main.cpp
)

target_link_libraries(zhenEngine PRIVATE
    "${CMAKE_SOURCE_DIR}/third_party/GLFW/lib/glfw3.lib"
)

target_include_directories(zhenEngine PRIVATE
    include/
    third_party/GLFW/include/
)
