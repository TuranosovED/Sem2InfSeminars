#include <stdio.h>
#include <stdbool.h>

#include "FileWorking.h"
#include "defines.h"
#include "convention.h"

int main()
{
    char array[SIZE];
    EnterStr(array);
    printf("answer is %d",HexToDecConvention(array));
    return 0;
}