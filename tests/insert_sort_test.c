#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "insert_sort.h"

int compare_arrays(int *arr1, int *arr2, int len) {
    for(int i = 0; i < len; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}

void test_insert_sort() {
    int arr1[] = {1,2,3};
    int arr2[] = {1,2,3};
    insert_sort(arr1, 3);
    CU_ASSERT(compare_arrays(arr1, arr2, 3) == 1);
    int arr3[] = {};
    int arr4[] = {};
    insert_sort(arr3, 0);
    CU_ASSERT(compare_arrays(arr3, arr4, 0) == 1);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Insert Sort Test Suite", 0, 0);

    CU_add_test(suite, "test of insert_sort functions", test_insert_sort);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
