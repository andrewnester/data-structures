#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "vector/vector_test.h"
#include "list/single_linked_list_test.h"

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_init),
            cmocka_unit_test(test_get),
            cmocka_unit_test(test_is_empty),
            cmocka_unit_test(test_size),
            cmocka_unit_test(test_insert),
            cmocka_unit_test(test_remove),
            cmocka_unit_test(test_push_back),
            cmocka_unit_test(test_is_empty_list),
            cmocka_unit_test(test_push_front),
            cmocka_unit_test(test_single_linked_list_top_front),
            cmocka_unit_test(test_single_linked_list_pop_front),
            cmocka_unit_test(test_single_linked_list_push_back),
            cmocka_unit_test(test_single_linked_list_pop_back),
            cmocka_unit_test(test_single_linked_list_top_back),
            cmocka_unit_test(test_single_linked_list_find),
            cmocka_unit_test(test_single_linked_list_add_before),
            cmocka_unit_test(test_single_linked_list_remove),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}