#include "vector_test.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../src/vector/vector.h"

void test_init(void **state) {
    vector v = init_vector();
    assert_int_equal(v.size, 0);
    assert_int_equal(v.capacity, INITIAL_CAPACITY);
}

void test_push_back(void **state) {
    vector v = init_vector();
    int error = 0;

    push_back(&v, 1, &error);
    assert_int_equal(error, 0);
    assert_int_equal(v.size, 1);
    assert_int_equal(v.capacity, INITIAL_CAPACITY);

    push_back(&v, 2, &error);
    assert_int_equal(error, 0);
    assert_int_equal(v.size, 2);
    assert_int_equal(v.capacity, INITIAL_CAPACITY);

    push_back(&v, 3, &error);
    assert_int_equal(error, 0);
    assert_int_equal(v.size, 3);
    assert_int_equal(v.capacity, INITIAL_CAPACITY * 2);

    push_back(&v, 4, &error);
    assert_int_equal(error, 0);
    assert_int_equal(v.size, 4);
    assert_int_equal(v.capacity, INITIAL_CAPACITY * 2);

    push_back(&v, 5, &error);
    assert_int_equal(error, 0);
    assert_int_equal(v.size, 5);
    assert_int_equal(v.capacity, INITIAL_CAPACITY * 4);
}

void test_size(void **state) {
    vector v = init_vector();
    assert_int_equal(size(v), 0);

    int error = 0;
    push_back(&v, 1, &error);
    assert_int_equal(size(v), 1);
}

void test_is_empty(void **state) {
    vector v = init_vector();
    assert_true(is_empty(v));

    int error = 0;
    push_back(&v, 1, &error);
    assert_false(is_empty(v));
}

void test_get(void **state) {
    vector v = init_vector();
    int error = 0;

    push_back(&v, 1, &error);
    push_back(&v, 2, &error);
    push_back(&v, 3, &error);
    push_back(&v, 4, &error);

    assert_int_equal(get(v, 0, &error), 1);
    assert_int_equal(error, 0);
    assert_int_equal(get(v, 1, &error), 2);
    assert_int_equal(error, 0);
    assert_int_equal(get(v, 2, &error), 3);
    assert_int_equal(error, 0);
    assert_int_equal(get(v, 3, &error), 4);
    assert_int_equal(error, 0);
    assert_int_equal(get(v, 4, &error), 0);
    assert_int_equal(error, 1);
}

void test_insert(void **state) {
    vector v = init_vector();
    int error = 0;

    push_back(&v, 1, &error);
    push_back(&v, 2, &error);

    insert(&v, 1, 3, &error);
    assert_int_equal(error, 0);
    assert_int_equal(size(v), 3);

    assert_int_equal(get(v, 1, &error), 3);
    assert_int_equal(error, 0);
    assert_int_equal(get(v, 2, &error), 2);
    assert_int_equal(error, 0);

    insert(&v, 1, 4, &error);
    assert_int_equal(error, 0);
    assert_int_equal(size(v), 4);

    assert_int_equal(get(v, 1, &error), 4);
    assert_int_equal(error, 0);
    assert_int_equal(get(v, 2, &error), 3);
    assert_int_equal(error, 0);
    assert_int_equal(get(v, 3, &error), 2);
    assert_int_equal(error, 0);

    insert(&v, 100, 4, &error);
    assert_int_equal(error, 1);
}

void test_remove(void **state) {
    vector v = init_vector();
    int error = 0;

    push_back(&v, 1, &error);
    push_back(&v, 2, &error);
    push_back(&v, 3, &error);
    push_back(&v, 4, &error);

    remove(&v, 1, &error);
    assert_int_equal(error, 0);
    assert_int_equal(size(v), 3);

    assert_int_equal(get(v, 1, &error), 3);
    assert_int_equal(error, 0);

    remove(&v, 100, &error);
    assert_int_equal(error, 1);
}