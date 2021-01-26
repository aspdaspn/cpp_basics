CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(hello)
add_executable(hello.bin src/hello.cpp)
target_include_directories(hello.bin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
