CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(hw03)
add_executable(hw03.bin src/external.cpp src/main.cpp) 
target_include_directories(hw03.bin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
