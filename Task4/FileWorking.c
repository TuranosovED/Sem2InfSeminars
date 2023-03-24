#include "FileWorking.h"
#include "defines.h"

bool cheak(char sign)
{
    if((sign >= '0' && sign <= '9') || (sign >= 'a' && sign <= 'f') || (sign >='A' && sign <= 'F'))
        return true;
    else return false;
}

int Len(char *str)
{
    int len =0;
    for(int i =0;str[i] !='\0';i++)
        len++;
    return len;
}

void EnterStr(char *array)
{
    char c;
    int i;
    for(i =0;((c = getchar()) != '\n') && (i < SIZE);)
    {   
        if(cheak(c))
        {
            array[i] = c;
            i++;
        }
    }
    if(i != (SIZE))array[i]='\0';
}

void StrRevers(char** array,int size)
{
    int j = 0;
    char* new_array = (char*)malloc((size + 1) * sizeof(char));
    for (int i = size-1; i>=0; i--)
    {
        new_array[j] = (*array)[i];
        j++;
    }
    new_array[j] = '\0';
    free(*array);
    (*array) = new_array;
}