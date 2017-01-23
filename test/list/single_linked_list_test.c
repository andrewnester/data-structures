#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <ntsid.h>
#include "../../src/list/single_linked.h"


void test_is_empty_list(void **state) {
    SingleLinkedList list = {};
    assert_true(single_linked_list_is_empty(list));

    SingleLinkedListNode root;
    list.head = &root;
    list.tail = &root;
    assert_false(single_linked_list_is_empty(list));
}

void test_push_front(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_push_front(&list, 1, &error);
    assert_int_equal(error, 0);
    assert_int_equal(list.head->value, 1);
    assert_null(list.head->next);


    single_linked_list_push_front(&list, 2, &error);
    assert_int_equal(error, 0);
    assert_int_equal(list.head->value, 2);
    assert_non_null(list.head->next);
    assert_int_equal(list.head->next->value, 1);
}

void test_single_linked_list_pop_front(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_push_front(&list, 3, &error);
    single_linked_list_push_front(&list, 2, &error);
    single_linked_list_push_front(&list, 1, &error);

    int value = single_linked_list_pop_front(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 1);

    value = single_linked_list_pop_front(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 2);

    value = single_linked_list_pop_front(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 3);

    single_linked_list_pop_front(&list, &error);
    assert_int_equal(error, 1);
    assert_null(list.head);
    assert_null(list.tail);
}

void test_single_linked_list_top_front(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_top_front(&list, &error);
    assert_int_equal(error, 1);

    single_linked_list_push_front(&list, 1, &error);

    error = 0;
    int value = single_linked_list_top_front(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 1);


    value = single_linked_list_top_front(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 1);
}

void test_single_linked_list_push_back(void **state)
{
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_push_back(&list, 1, &error);
    assert_int_equal(error, 0);
    single_linked_list_push_back(&list, 2, &error);
    assert_int_equal(error, 0);
    single_linked_list_push_back(&list, 3, &error);
    assert_int_equal(error, 0);

    assert_non_null(list.head);
    assert_non_null(list.tail);
    assert_int_equal(list.head->value, 1);
    assert_int_equal(list.head->next->value, 2);
    assert_int_equal(list.head->next->next->value, 3);

    assert_null(list.head->next->next->next);
}

void test_single_linked_list_pop_back(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_push_back(&list, 3, &error);
    single_linked_list_push_back(&list, 2, &error);
    single_linked_list_push_back(&list, 1, &error);

    int value = single_linked_list_pop_back(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 1);

    value = single_linked_list_pop_back(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 2);

    value = single_linked_list_pop_back(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 3);

    single_linked_list_pop_front(&list, &error);
    assert_int_equal(error, 1);
    assert_null(list.head);
    assert_null(list.tail);
}

void test_single_linked_list_top_back(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_top_back(&list, &error);
    assert_int_equal(error, 1);

    single_linked_list_push_back(&list, 1, &error);

    error = 0;
    int value = single_linked_list_top_back(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 1);


    value = single_linked_list_top_back(&list, &error);
    assert_int_equal(error, 0);
    assert_int_equal(value, 1);
}

void test_single_linked_list_find(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_push_back(&list, 3, &error);
    single_linked_list_push_back(&list, 2, &error);
    single_linked_list_push_back(&list, 1, &error);

    SingleLinkedListNode *n = single_linked_list_find(list, 2);
    assert_int_equal(n->value, 2);
    assert_int_equal(n->next->value, 1);

    n = single_linked_list_find(list, 40);
    assert_null(n);
}

void test_single_linked_list_remove(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_push_back(&list, 3, &error);
    single_linked_list_push_back(&list, 2, &error);
    single_linked_list_push_back(&list, 1, &error);

    single_linked_list_remove(&list, 2, &error);
    assert_int_equal(error, 0);
    assert_null(single_linked_list_find(list, 2));

    single_linked_list_remove(&list, 3, &error);
    assert_int_equal(error, 0);
    assert_null(single_linked_list_find(list, 3));

    single_linked_list_remove(&list, 1, &error);
    assert_int_equal(error, 0);
    assert_null(single_linked_list_find(list, 1));

    assert_null(list.head);
    assert_null(list.tail);
}

void test_single_linked_list_add_before(void **state) {
    SingleLinkedList list = {};

    int error = 0;
    single_linked_list_push_back(&list, 3, &error);
    single_linked_list_push_back(&list, 2, &error);
    single_linked_list_push_back(&list, 1, &error);

    single_linked_list_add_before(&list, 2, 10, &error);
    assert_int_equal(error, 0);
    assert_int_equal(list.head->next->value, 10);
    assert_int_equal(list.head->next->next->value, 2);

    single_linked_list_add_before(&list, 100, 10, &error);
    assert_int_equal(error, 1);
}