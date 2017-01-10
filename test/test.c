#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "vector/vector_test.h"

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_init),
            cmocka_unit_test(test_push_back),
            cmocka_unit_test(test_get),
            cmocka_unit_test(test_is_empty),
            cmocka_unit_test(test_size),
            cmocka_unit_test(test_insert),
            cmocka_unit_test(test_remove),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}