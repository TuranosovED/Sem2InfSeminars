#include "BitsWorking.h"

char* CreateMaskForOddBits(int size)
{   
    bool trigger = true;
    char *new_array = (char*)malloc((size+1)*sizeof(char));
    for(int i = size-1;i>=0;i--)
    {
        if(trigger)new_array[i] = '1';
        else new_array[i] = '0';
        trigger = !trigger;
    }
    new_array[size] = '\0';
    return new_array;
}

int OddBitsCount(char *mask,char*BoolNumber,int size)
{
    int counter = 0;
    for(int i =0;i<size;i++)
    {
        if((((int)mask[i]-'0') & ((int)BoolNumber[i]-'0')) == 1)counter++;
    }
    return counter;
}