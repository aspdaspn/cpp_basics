CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(hw06)
add_executable(hw07.bin src/main.cpp) 
target_include_directories(hw07.bin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
