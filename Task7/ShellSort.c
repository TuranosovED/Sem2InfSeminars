#include <stdlib.h>
#include <stdio.h>
#include "SortStructs.h"

void print(arrayConfig *array)
{
    for(int i =0;i< array->count;i++)
    {
        printf("%d ",array->mas[i]);
    }
    putchar('\n');
}

void InsertSort(arrayConfig *array,int length,int start)
{
    int buffer;
    for(int i =start + length;i<array->count;i+=length)
    {
        buffer = array->mas[i];
        for(int j = i-length;j>=0;j-=length)
        {
            if(buffer<array->mas[j])
            {
                array->mas[j+length] = array->mas[j];
                array->mas[j] = buffer;
            }
        }
    }
}

arrayConfig DataRead()
{
    arrayConfig array;
    scanf("%d",&(array.count));
    array.mas = (int*)malloc(sizeof(int) * array.count);
    
    for(int i =0;i<array.count;i++)
        scanf("%d",&(array.mas[i]));
    return array;
}

void ShellSort(arrayConfig *array)
{
    int length = array->count/2; //длина и количество групп

    if(array->count%2 != 0)
        length++; 
    while(length != 0) //условие окончания сортировки
    {
        for(int start = 0;start<length;start++)//пробегаем все группы
            InsertSort(array,length,start);
        length/=2;
    }
}

int main()
{
    arrayConfig array = DataRead();
    ShellSort(&array);
    print(&array);
    return 0;
}