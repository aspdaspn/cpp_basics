CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(hw05)
add_executable(hw05.bin src/main.cpp) 
target_include_directories(hw05.bin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
