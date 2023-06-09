#include "FileRead.h"
#include <string.h>
arrayConfig ReadFile()
{
    int valueCount = 0; //кол-во элементов
    FILE *f = fopen("SortData.txt","r");
    char c;
    while((c = fgetc(f))!= EOF)
    {
        if(c == '\n')valueCount++;
    }
    valueCount++;
    
    fclose(f);
    f = fopen("SortData.txt","r");
    int *mas = malloc(sizeof(int) * valueCount);
    int i=0;
    int counter = 0;
    char *buffer = NULL;
    int buffer_size = 0;
    int trigger = 0;
    while((c = fgetc(f))!= EOF)
    {
        if((c!='\n') && (c !='-'))PushLine(&buffer,buffer_size++,c);
        else if (c == '-')trigger = 1;
        else 
        {
            PushLine(&buffer,buffer_size++,'\0');
            if(trigger)
                 mas[counter++] = atoi(buffer) * (-1);
            else mas[counter++] = atoi(buffer);
            trigger = 0;
            free(buffer);
            buffer = NULL;
            buffer_size=0;
        } 

    }
    mas[counter++] = atoi(buffer);
    free(buffer);
    fclose(f);
    arrayConfig array = {mas,valueCount};
    
    return array;
}
