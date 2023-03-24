#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

void Task1()
{
    char s[start_memory];
    char buffer = '\0'; //нужен для исключения повторов при записи a-c-d
    int shift = 0;//сдвиг, нужен чтобы выводить ласт символ
    input(s);
    int i;
    int triger=0;
    for (i = 0; (i < start_memory) && (s[i] != '\0') && (s[i] !='\n') && (s[i+1]!='\n') && (s[i+2]!='\n');)
    {
        if (s[i] != '-' && s[i + 1] == '-' && s[i + 2] != '-') //проверка на конструкцию a-c 
        {
            if (buffer == s[i])shift = 1; //так как в buffer лежит 1 символ, то сверяя его при смещении тройки с новым 1 символом, мы проверяем на комбинцию a-c-d
            else shift = 0;
            buffer = s[i + 2];
            if (s[i] > s[i + 2]) // смотрим как a-d или d - a
            {
                for (int j = s[i] - shift; j != s[i + 2] - 1; j--)putchar(j);
            }
            else
            {
                for (int j = s[i] + shift; j != s[i + 2] + 1; j++)putchar(j);
            }
            i += 2;
            triger = 1; //если 1 символ уже был выведен
        }
        else 
        {
            if(triger != 1)putchar(s[i]); 
            else triger = 0;
            i++;
        }
    }
    if (i < 50 && s[i] != '\n' && triger != 1)putchar(s[i]); //костыль, так как время жмет
    if(i+1 < 50 && s[i+1] != '\n')putchar(s[i+1]);
    putchar('\n');
}