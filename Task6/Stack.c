#include "Stack.h"
void printStack(Stack *stack)
{
    for(int i =0;i<(stack->size);i++)
        printf("%d %d \n",(stack->array)[i].first , (stack->array)[i].last);
}

int Top(Stack *stack) // возвращает индекс вверхнего элемента
{
    return (stack->size - 1);
}

points Pop(Stack *stack) // вытаскивает вверхний элемент и возвращает его
{
    points value = stack->array[stack->size - 1];
    points *buffer = (points *)malloc(sizeof(points) * ((stack->size) - 1));
    for (int i = 0; i < (stack->size - 1); i++)
        buffer[i] = stack->array[i];
    free(stack->array);
    stack->array = buffer;
    stack->size--;
    return value;
}

void Push(Stack *stack, points value)
{
    points *buffer = (points *)malloc(sizeof(points) * (stack->size + 1));
    for (int i = 0; i < (stack->size); i++)
        buffer[i] = stack->array[i];
    buffer[stack->size] = value;
    free(stack->array);
    stack->size++;
    stack->array = buffer;
}