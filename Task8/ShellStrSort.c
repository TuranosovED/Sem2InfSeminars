#include "ShellStrSort.h"

void print(char ** array,int count)//вывод массива строк в консоль
{
    for(int i =0;i<count;i++)
        puts(array[i]);
}

void clearBuffer()//очистка буфера консоли
{
    char c;
    while((c = getchar())!='\n');
}

int maxLen(char **array,int count)//возвращает самую длинную строку
{
    int max = 0;
    for(int i=0;i<count;i++)
        if(max < len(array[i]))max = len(array[i]);
    return max;
}

void InsertSort(char ***array,int count,int max,int length,int start)
{
    char *buffer;
    for(int i =start + length;i<count;i+=length) //сортируемая строка
    {
        buffer = (*array)[i];
        for(int j = i-length;j>=0;j-=length) //сравниваемая строка 
        {
            for(int charCounter = 0;charCounter<max;charCounter++) //проверяем символы строк
            {
                if(len((*array)[i]) < len((*array)[j])) //если длины различны меняем местами
                {
                    (*array)[j+length] = (*array)[j];
                    (*array)[j] = buffer;
                    break;
                }
                else if(len((*array)[i]) == len((*array)[j])) //если длины совпадают, проверяем символы
                {
                    if((int)((*array)[i][charCounter]) < (int)((*array)[j][charCounter]))
                    {
                        (*array)[j+length] = (*array)[j];
                        (*array)[j] = buffer;
                        break;
                    }
                }
            }
        }
    }
}

void ShellSort(char ***array,int count)
{
    int length = count/2; //длина и количество групп
    int max = maxLen(*array,count) + 1;
    if(count%2 != 0)
        length++; 
    while(length != 0) //условие окончания сортировки
    {
        for(int start = 0;start<length;start++)//пробегаем все группы
            InsertSort(array,count,max,length,start);
        length/=2;  
    }
}