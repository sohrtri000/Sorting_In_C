#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "merge_sort.h"

void test_merge_sort() {
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Merge Sort Test Suite", 0, 0);

    CU_add_test(suite, "test of merge_sort functions", test_merge_sort);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
