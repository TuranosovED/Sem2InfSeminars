#include "quicksort.h"

void print(arrayConfig *array)
{
    for(int i =0;i< array->count;i++)
    {
        printf("%d ",array->mas[i]);
    }
    putchar('\n');
}

void quicksort(arrayConfig *array,Stack *stack)
{
    int first = 0;
    int last = array->count-1;
    int left = 0;
    int right = array->count-1;
    int middle = array->mas[(left + right) / 2];

    points p = {0,right, array->mas[(left + right) / 2]};

    points p1;
    points p2;

    Push(stack,p);

    while(stack->size != 0)
    {
        p = Pop(stack);
        first = p.first;
        last = p.last;
        left = p.first;
        right = p.last;
        middle = array->mas[(p.first + p.last) / 2];

        do
        {
            while (array->mas[left] < middle) left++;
            while (array->mas[right] > middle) right--;
            if (left <= right)
            {
                int tmp = array->mas[left];
                array->mas[left] = array->mas[right];
                array->mas[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);

        if (first < last)
        {
            p1.first = first;
            p1.last = right;
            p2.first = left;
            p2.last = last;
            Push(stack,p1);
            Push(stack,p2);
        }
    }
}