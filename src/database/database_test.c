// Created by nicolas on 20/09/23.
//
#include "database.h"
#include "CUnit/Basic.h"

int init_suite() {
    return 0;
}

int clean_suite() {
    database_remove("database_name");
    database_remove("database_already_exist");

    return 0;
}

void test_database_create() {
    CU_ASSERT(database_create("database_name") == 0);
}

void test_database_already_exist() {
    database_create("database_already_exist");
    CU_ASSERT(database_create("database_already_exist") == -1000);
}

void test_database_remove() {
    database_create("database_to_remove");
    CU_ASSERT(database_remove("database_to_remove") == 0);
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
    CU_add_test(pSuite, "test database creation", test_database_create);
    CU_add_test(pSuite, "test database already exist creation", test_database_already_exist);
    CU_add_test(pSuite, "test remove database", test_database_remove);


    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}