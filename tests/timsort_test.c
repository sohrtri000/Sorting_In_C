#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "timsort.h"

void test_timsort() {
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Timsort Test Suite", 0, 0);

    CU_add_test(suite, "test of insert_sort functions", test_timsort);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
