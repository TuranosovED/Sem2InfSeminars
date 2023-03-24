#include "Input.h"
#include <stdio.h>
void input(char* s) //ввод строчек
{
    char c;
    int i;
    for (i = 0; ((c = getchar()) != '\n') && (i < start_memory); i++)
    {
        s[i] = c;
    }
    if (i != start_memory)s[i] = '\n';
}

void ClearBuffer()
{
    char c;
    while((c = getchar()) != '\n')
    {
        continue;
    }
}