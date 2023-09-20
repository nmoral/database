//
// Created by nicolas on 20/09/23.
//
#include <sys/stat.h>
#include "database.h"

int database_create(char* database_name)
{
    int _database_status;
    if (0 == (_database_status = _database_already_exist(database_name))) {
        return -1000;
    }
    return mkdir(database_name, 0700);
}

int database_remove(char* database_name)
{
    int _database_status;
    if (0 != (_database_status = _database_already_exist(database_name))) {
        return -1001;
    }

    return remove(database_name);
}

int _database_already_exist(char* database_name) {
    struct stat st;
    if (stat(database_name, &st) == 0 && S_ISDIR(st.st_mode)) {
        return 0;
    }

    return -1;
}