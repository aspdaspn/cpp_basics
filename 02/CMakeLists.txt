CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(tick_tack_toe)
add_executable(ttt.bin src/main.cpp) 
target_include_directories(ttt.bin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
