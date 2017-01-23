cmake_minimum_required(VERSION 3.6)
set(TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)

find_package(cmocka)

add_executable (unittest test.c vector/vector_test.c vector/vector_test.h
        list/single_linked_list_test.h list/single_linked_list_test.c)
target_link_libraries(unittest vector single_linked cmocka)

enable_testing()
add_test(MyTest unittest)