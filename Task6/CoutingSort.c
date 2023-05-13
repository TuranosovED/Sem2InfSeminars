#include "CountingSort.h"

int Min(arrayConfig *array)
{
    int min = 2147483647;
    for(int i =0;i<array->count;i++)
    {
        if(array->mas[i] < min)min = array->mas[i];
    }
    return min;
}

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
    int minValue = Min(array);
    arrayConfig buffer;
    buffer.count = 0;
    buffer.mas = NULL;
    int *additionalArrayPositive = calloc(maxValue+1,sizeof(int));
    int *additionalArrayNegative = calloc((minValue+1)*(-1),sizeof(int));
    for(int i = 0 ; i < (array->count) ; i++)
    {
        if(array->mas[i] >= 0)additionalArrayPositive[array->mas[i]]++;
        else additionalArrayNegative[(array->mas[i]) * (-1)]++;
    }

    for(int i = (minValue * (-1)) ; i > 0; i--)
        for(int j =0;j<additionalArrayNegative[i];j++)
            {
                VectorPush(&buffer.mas,buffer.count, i*(-1));
                buffer.count++;
            }
    
    for(int i =0 ; i < (maxValue+1) ; i++)
        for(int j =0;j<additionalArrayPositive[i];j++)
            {
                VectorPush(&buffer.mas,buffer.count, i);
                buffer.count++;
            }

   
    free(array->mas);
    array->mas = buffer.mas;
    array->count = buffer.count;
}