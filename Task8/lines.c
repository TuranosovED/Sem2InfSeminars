#include "lines.h"

void Push(char **line,int size,char value)
{
    char *buffer = (char *)malloc(sizeof(char)*(size+1));
    for(int i =0;i<size;i++)
        buffer[i] = (*line)[i];
    buffer[size] = value;
    free(*line);
    (*line) = buffer;
}

char* ReadStr(int trigger) //1 - сброс статической переменной, функция ввода строк из консоли
{
    static int counter = 1;

    if(trigger == 1)
    {
        counter = 1;
        return NULL;
    }
    
    char* line = NULL;
    char c;
    int size =  0;
    printf("enter str %d: ",counter++); 
    while((c = getchar())!='\n')
        Push(&line,(size++),c);
    Push(&line,(size++),'\0');
    return(line);
}

int len(char *s) //возвращает индекс ласт элемента, не \0
{
    int count;
    for(count=0; s[count] !='\0';count++);
    return count-1;
}