#include "lines.h"

void ClearBuffer()
{
    char c;
    while((c = getchar())!='\n');
}

void PushLine(char **s,char value,int size)
{
    char *buffer = (char*)malloc(sizeof(char) * (size+1));
    for(int i =0;i<size;i++)
        buffer[i] = (*s)[i];
    buffer[size] = value;
    free(*s);
    (*s) = buffer;
}

char * EnterStr()
{
    char c;
    char *s = NULL;
    int size = 0;
    ClearBuffer();
    while((c = getchar())!= '\n')
        PushLine(&s,c,size++);
    PushLine(&s,'\0',size);
    return s;
}

int len(char *s)
{
    int len =0;
    for(int i =0;s[i] !='\0';i++)
        len++;
    return len;
}
