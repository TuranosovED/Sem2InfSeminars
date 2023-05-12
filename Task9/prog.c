#include <stdio.h>
#include <stdlib.h>

int printLine(FILE *f)
{
    char c;
    if(f == NULL)return 0;
    while(((c = fgetc(f)) != EOF))
    {
        if(c == '\n')
        {
            putchar(c);
            return 1;
        }    
        putchar(c);
    }
    putchar('\n');
    fclose(f);
    return 0;
}

int main(int argc, char* argv[])
{
    FILE *f1 = fopen(argv[1],"r");
    if(f1 == NULL)
    {
        puts("first file not founded");
        return 0;
    }
    FILE *f2 = fopen(argv[2],"r");
    if(f2 == NULL)
    {
        puts("second file not founded");
        return 0;
    }
    while(1)
    {
        if(!printLine(f1))
        {
            while(printLine(f2));
            break;
        }
        if(!printLine(f2))
        {
            while(printLine(f1));
            break;
        }
    }
    return 0;
}