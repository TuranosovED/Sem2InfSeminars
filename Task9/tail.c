#include <stdio.h>
#include <stdlib.h>

int LinesCount(char *name) //возвращает кол-во строк в файле
{
    char c;
    int linesCount = 0;
    FILE* f = fopen(name,"r");
    while((c = fgetc(f))!= EOF)
    {
        if(c == '\n')linesCount++;
    }
    linesCount++;
    fclose(f);
    return linesCount;
}

void tail(char *name,int count)
{
    char c;
    int enterCounts = 0;
    int linesCount = LinesCount(name);
    if((linesCount - count >= 0 && (count > 0)))linesCount -= count;
    else linesCount = 0;
    FILE* f = fopen(name,"r");
    if(f == NULL)puts("file is not founded!\n");
    else
    {
        while((c = fgetc(f)) != EOF)
        {
            if(enterCounts >= linesCount)putchar(c);
            if(c == '\n')enterCounts++;
        }
    }
    fclose(f);
}

int main(int argc, char* argv[])
{
    tail(argv[1],atoi(argv[2]));
    return 0;
}