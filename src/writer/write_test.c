//
// Created by nicolas on 20/09/23.
//
#include <stdio.h>
#include "write.h"
#include "CUnit/Basic.h"

static FILE* test_file = NULL;

const char* FILE_TEST_NAME = "write_test_file.txt";

int init_suite() {

    test_file = fopen(FILE_TEST_NAME, "w+");

    return NULL == test_file ? -1 : 0;
}

int clean_suite() {
    int close = fclose(test_file);
    if (close != 0) {
        return close;
    }

    return remove(FILE_TEST_NAME);
}

void test_write() {
    CU_ASSERT( write(test_file, "content") == 0);
}



int main() {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if (NULL == CU_add_test(pSuite, "test of write()", test_write))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}