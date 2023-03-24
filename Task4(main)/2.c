#include "2.h"

void Task2()
{
    char EnterArray[SIZE];
    char *BoolArray;
    EnterStr(EnterArray);
    int len = DecToBoolConvention(HexToDecConvention(EnterArray),&BoolArray);
    printf("%d \n",OddBitsCount(CreateMaskForOddBits(len),BoolArray,len));
    //printf("%d %s\n",len,BoolArray);
    //printf("%s",CreateMaskForOddBits(len));
}