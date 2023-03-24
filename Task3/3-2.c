#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

void del(char **s1,char*s2)
{
    int trig;
    int shift=0; //сдвиг
    char *buffer = (char*)calloc(start_memory,sizeof(char));
    int i;
    for(i =0;(i<start_memory) && ((*s1)[i] != '\n');i++)
    {
        trig = 1; //проверка
        for(int j =0;j<start_memory;j++) //проверяем символ 1 строки на равенство каждому из символов 2 
        {
            if((*s1)[i] == s2[j]) 
            {
                trig = 0;
                break;
            }
        }
        if(trig)buffer[i - shift] = (*s1)[i];//если символ подходит сохраняем его, если нет, то прибавляем сдвиг
        else shift++;
    }
    buffer[i-shift] = '\0';
    
    free(*s1);
    (*s1) = buffer; 
}

void Task2()
{
    char *s1 =(char*)calloc(start_memory,sizeof(char));
    char s2[start_memory];
    input(s1);
    input(s2);
    del(&s1,s2);
    printf("%s",s1);
    putchar('\n');
}