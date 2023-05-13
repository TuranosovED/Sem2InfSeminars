#include "FileRead.h"
#include "BinarySearch.h"
#include "Radix.h"
#include "CountingSort.h"
#include "quicksort.h"
#include "lines.h"
#include "Stack.h"

#define swap(a, b , type) type c = a; \
                          a = b;      \
                          b = c;

int main()
{
    arrayConfig array; //сортируемый список
    
    Stack stack; //стэк
    stack.array = NULL;
    stack.size = 0;

    int index = 2; //макс разряд
    array = ReadFile2();
    puts("enter a:");
    int a = atoi(ReadStr());
    puts("enter b:");
    int b = atoi(ReadStr());
    
    printf("\nbefore swap a - %d b - %d\n",a,b);
    swap(a,b,int);
    printf("after swap a - %d b - %d\n",a,b);
    
    puts("\narray:");
    print(&array);
    quicksort(&array,&stack);
    puts("result qs:");
    print(&array);
    
    puts("\nenter key for binary search: ");
    int key = atoi(ReadStr());
    printf("result of search: index - %d\n",Search(array,0,array.count-1,key));

    free(array.mas);
    array = ReadFile2();

    puts("\narray:");
    print(&array);

    for(int i =0;i<index;i++)
    {
        fragmentation(&array,i+1);//radix;
    }
    
    puts("result radix:");
    print(&array);

    free(array.mas);
    array = ReadFile2();

    puts("\narray:");
    print(&array);
    CountingSort(&array);
    puts("result couting sort:");
    print(&array);
    putchar('\n');

    return 0;
}