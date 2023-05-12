#include "FileRead.h"
arrayConfig ReadFile()  //считываем массив из файла
{
    int valueCount = 0; //кол-во элементов
    int c; // значение из файла 
    FILE *f = fopen("SortData.txt","r");

    while(fscanf(f,"%d",&c) != EOF)
        valueCount++;
    fclose(f);
    f = fopen("SortData.txt","r");
    int *mas = malloc(sizeof(int) * valueCount);
    int i=0;
    while((fscanf(f,"%d",&c)) != EOF)
    {
        mas[i] = c;
        i++;
    }
    fclose(f);
    arrayConfig array = {mas,valueCount};
    
    return array;
}