#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

void Task3(int mode)
{
    char s1[start_memory];
    int codes[256];
    int max = 0;
    input(s1);
    for (int i = 0; i < 256; i++)
    {
        codes[i] = 0;
    }
    
    for (int i = 0; (s1[i] != '\n') && (s1[i] != '\0'); i++)
    {
        codes[s1[i]]++;
    }

    if (mode == '1')
    {
        for (int i = 0; i < 256; i++)
        {
            if (max < codes[i])max = codes[i];
        }

        for (int i = max; i > 0; i--)
        {
            for (int j = 48; j < 58; j++)
            {
                if (codes[j] != 0 && (codes[j] == i))
                {
                    putchar('#');
                    if (codes[j] > 1)codes[j]--;
                }
                else putchar(' ');
            }

            putchar('\n');
        }
        for (int i = 48; i < 58; i++)
        {
            putchar(i);
        }
    }

    else if(mode == '0')
    {
        for (int i = 48; i < 58; i++)
        {
            printf("%c%c", i, ':');
            if (codes[i] != 0)
            {
                for (int j = 0; j < codes[i]; j++)
                {
                    putchar('#');
                }
            }
            putchar('\n');
        }
    }
}