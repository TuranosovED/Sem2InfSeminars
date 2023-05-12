#include "CountingSort.h"

int Max(arrayConfig *array)
{
    int max = 0;
    for(int i =0;i<array->count;i++)
    {
        if(array->mas[i] > max)max = array->mas[i];
    }
    return max;
}

void CountingSort(arrayConfig *array)
{
    int maxValue = Max(array);
    arrayConfig buffer;
    buffer.count = 0;
    buffer.mas = NULL;
    int *additionalArray = calloc(maxValue+1,sizeof(int));
    for(int i = 0 ; i < (array->count) ; i++)
        additionalArray[array->mas[i]]++;

    for(int i =0 ; i < (maxValue+1) ; i++)
        for(int j =0;j<additionalArray[i];j++)
            {
                VectorPush(&buffer.mas,buffer.count, i);
                buffer.count++;
            }

   
    free(array->mas);
    array->mas = buffer.mas;
    array->count = buffer.count;
}