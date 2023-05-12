#include "Radix.h"
void fragmentation(arrayConfig *array, int index)
{
    arrayConfig buffer[10];
    for(int i =0;i<10;i++)
    {
        buffer[i].count = 0;
        buffer[i].mas = NULL;
    }

    int number;
    
    for(int i = 0; i < array->count;i++)
    {
        number = ((array->mas[i])/(int)pow(10,index - 1)) % 10 ;

        VectorPush(&(buffer[number].mas), buffer[number].count,array->mas[i]);
        buffer[number].count++;
    }

    int *newMas = malloc(sizeof(int) * array->count);
    int counter = 0;
    for(int i =0;i<10;i++)
    {
        for(int j = 0;j<buffer[i].count;j++)
        {
            newMas[counter] = buffer[i].mas[j];
            counter++;
        }
    }
    free(array->mas);
    array->mas = newMas;
}