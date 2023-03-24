#include "MemoryWorking.h"

void Push(char** array, int size, int number)
{
    int i;
    char* new_array = (char*)malloc((size + 2) * sizeof(char));
    for (i = 0; i < size; i++)
    {
        new_array[i] = (*array)[i];
    }
    new_array[i] = number + '0';
    new_array[i + 1] = '\0';
    free(*array);
    (*array) = new_array;
}