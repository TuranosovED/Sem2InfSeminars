#include "strend.h"

int strend(char *s,char *t)
{
    int sCount = len(s);
    for(int i = len(t);i >= 0;i--)
        if(t[i] != s[sCount--])return 0;
    return 1;
}