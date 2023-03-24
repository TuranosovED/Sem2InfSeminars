#include "convention.h"

int pow(int a,int b)
{
    int result = 1;
    for(b;b != 0;b--)
        result *=a;
    return result;
}

int HexToDecConvention(char* array)
{
    int result = 0;
    int counter = Len(array) - 1;
    for (int i = 0; array[i] != '\0'; i++)
    {
        if(array[i] >= '0' && array[i] <= '9')result += pow(16, counter) * ((int)(array[i] - '0'));
        else if(array[i] >= 'a' && array[i] <= 'f')result += pow(16, counter) * ((int)(array[i] - ConventionCoefficientForUppercaseLetters));
        else result += pow(16, counter) * ((int)(array[i] - ConventionCoefficientForCapitalLetters)); ////
        counter--;
    }
    return result;
}

int DecToBoolConvention(int number, char** str)
{
    int size = 0;
    char* array = (char*)malloc(sizeof(char));
    array[0] = '\0';
    while (number > 0)
    {
        Push(&array, size, number%2);
        number /= 2;
        size++;
    }
    StrRevers(&array, size);
    (*str) = array;
    return size;
}