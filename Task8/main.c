#include "ShellStrSort.h"
#include "lines.h"
#include "strend.h"

int main()
{
    //начало 1 номера
    char *s = ReadStr(0);
    char *t = ReadStr(0);
    printf("%d",strend(s,t));
    putchar('\n');
    //начало 2 номера
    int count  = 0;
    scanf("%d",&count);
    clearBuffer();
    
    char **array = (char**)malloc(sizeof(char*) * count);
    ReadStr(1);
    for(int i =0;i<count;i++)
        array[i] = ReadStr(0);
    ShellSort(&array,count);

    print(array,count);
    return 0;
}