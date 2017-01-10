cmake_minimum_required(VERSION 3.6)
project(data-strucures)
set(CMAKE_C_STANDARD 11)

add_subdirectory (src)
add_subdirectory (test)
enable_testing ()
add_test (NAME MyTest COMMAND Test)