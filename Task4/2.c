#include <stdio.h>
#include <stdbool.h>

#include "FileWorking.h"
#include "convention.h"
#include "BitsWorking.h"
#include "defines.h"

int main()
{
    char EnterArray[SIZE];
    char *BoolArray;
    EnterStr(EnterArray);
    int len = DecToBoolConvention(HexToDecConvention(EnterArray),&BoolArray);
    printf("%d \n",OddBitsCount(CreateMaskForOddBits(len),BoolArray,len));
    //printf("%d %s\n",len,BoolArray);
    //printf("%s",CreateMaskForOddBits(len));
    return 0;
}