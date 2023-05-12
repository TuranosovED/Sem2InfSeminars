#include "Vector.h"
void VectorPush(int **mas,int count, int value) //пробиваем на одно значение массив
{
    int * buffer = malloc(sizeof(int) * (count+1));
    for(int i =0;i<count;i++)
        buffer[i] = (*mas)[i];
    buffer[count] = value;
    if(*mas != NULL)
        free(*mas);
    *mas = buffer; 
}