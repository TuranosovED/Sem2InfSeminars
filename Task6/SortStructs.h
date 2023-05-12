#pragma once
typedef struct arrayConfig
{
    int *mas;
    int count;
}arrayConfig;

typedef struct points //под квик сорт
{
    int first;
    int last;
    int middle;
}points;

typedef struct Stack
{
    points *array;
    int size; //размер, соотв послед элемент size - 1  
}Stack;