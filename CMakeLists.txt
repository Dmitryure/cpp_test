cmake_minimum_required(VERSION 3.5.0)
project(oop VERSION 0.1.0)

set(CMAKE_CXX_STANDART 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB src_files
    "*.cpp"
    "src/*.cpp"
)

add_executable(oop ${src_files})