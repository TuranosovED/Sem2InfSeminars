#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    char* pointer;
    int size;
}line;

void push(line *s,char value)
{
    char * buffer = malloc(sizeof(char) * (s->size+2));
    for(int i =0;i<s->size;i++)
    {
        buffer[i] = s->pointer[i];
    }
    buffer[s->size] = value;
    buffer[s->size + 1]='\0';
    free(s->pointer);
    s->pointer = buffer;
    s->size++;
}

void input(line *s)
{
    char c;
    while((c = getchar()) != '\n')
        push(s,c);
}

int search(line s1,line s2)
{
    for(int i = 0;i<s1.size;i++)
        for(int j =0;j<s2.size;j++)
            if(s1.pointer[i] == s2.pointer[j])return i;
    return -1;
}

int main()
{
    line s1 = {NULL,0};
    line s2 = {NULL,0};
    input(&s1);
    input(&s2);
    printf("%d", search(s1,s2));
    return 0;
}