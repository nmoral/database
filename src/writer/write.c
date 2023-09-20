//
// Created by nicolas on 20/09/23.
//

#include <stdio.h>
#include "write.h"

struct test
{
    char* test;
};

int write(FILE* file, char* content)
{
    struct test test;
    test.test = content;

    int _char = fwrite(&test, sizeof(struct test), 1, file);

    return _char > 0 ? 0 : -1;
}