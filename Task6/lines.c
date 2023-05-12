#include "lines.h"

void PushLine(char **line,int size,char value)
{
    char *buffer = (char *)malloc(sizeof(char)*(size+1));
    for(int i =0;i<size;i++)
        buffer[i] = (*line)[i];
    buffer[size] = value;
    free(*line);
    (*line) = buffer;
}

char* ReadStr()
{
    char* line = NULL;
    char c;
    int size =  0;
    while((c = getchar())!='\n')
        PushLine(&line,(size++),c);
    PushLine(&line,(size++),'\0');
    return(line);
}