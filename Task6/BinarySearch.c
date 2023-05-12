#include "BinarySearch.h"

int Search(arrayConfig array,int first, int last, int key)
{
    if (array.mas[(first + last) / 2] != key)
    {
        if (key > array.mas[(first + last) / 2])
        {
            if (first > last)return -1;
            Search(array, (first + last) / 2 + 1, last, key);
        }
        else
        {
            if (first > last)return -1;
            Search(array, first, (first + last) / 2 - 1, key);
        }
    }
    else return (first + last) / 2;
}