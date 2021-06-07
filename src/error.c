#include "define.h"

void error(char *error)
{
    printf("Error %c", *error);
    exit(1);
}