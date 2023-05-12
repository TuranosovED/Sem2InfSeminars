#include <stdio.h>
#include <stdlib.h>
#define KeysCount 2 // кол-во допустимых ключей для программы

int CheakData(char**s,int *maxLines,int *maxSign) //p- Lines n - Signs
{
    int i = 1;
    int KeysTrigger = 0; //ключество ключей
    while(s[i] != NULL)
    {
        for(int j =0;s[i][j] != '\0';j++)
        {
            if(s[i][j] == '-' && s[i][j+1] != '\0')
            {
                switch (s[i][j+1])
                {
                case 'n':
                    if(s[i+1] != NULL && (atoi(s[i+1]) !=0))
                    {
                        *maxSign = atoi(s[i+1]);
                        i++;
                        KeysTrigger++;
                        break;
                    }
                    else
                    {
                        puts("Incorrect Signs Value");
                        return 0;
                    }
                    break;
                case 'p':
                    if(s[i+1] != NULL && (atoi(s[i+1]) !=0))
                    {
                        *maxLines = atoi(s[i+1]);
                        i++;
                        KeysTrigger++;
                        break;
                    }
                    else 
                    {
                        puts("Incorrect Lines Value");
                        return 0;
                    }
                    break;
                default:
                    puts("This Key is not allowed");
                    return 0;
                }
            }
            else
            {
                puts("Incorrect Keys");
                return 0;
            }
        }
        i++;
    }
    if(KeysTrigger == KeysCount)return 1;
    else 
    {
        puts("The number of keys is less than allowed");
        return 0;
    }
}   

int main(int argc, char* argv[])
{
    FILE* f = fopen("page.txt", "r");
    if (f == NULL)
    {
        puts("page.txt is not founded");
        return 0;
    }
    int maxLinesOnPage;
    int maxSignsInLine;

    if (!CheakData(argv,&maxLinesOnPage,&maxSignsInLine))
    {
        return 0;
    }

    int PagesCounter = 1;
    int LinesCounter = 0;
    int CharsCounter = 0;
    char c;
    char buf ='\0';
    while ((c = fgetc(f))!= EOF)
    {
        if(LinesCounter == maxLinesOnPage)
        {
            LinesCounter=0;
            CharsCounter=0;
            PagesCounter++;
        }
        if( (LinesCounter == 0) && (CharsCounter == 0))
        {
            printf("\n- Page %d -\n%d:",PagesCounter,LinesCounter+1);
            if(buf != '\n')
            {
                putchar(buf);
                buf = '\0';
                CharsCounter++;
            }
        }
        if(CharsCounter < maxSignsInLine)
        {
            if(c == '\n')
            {
                LinesCounter++;
                CharsCounter = 0;
                if(LinesCounter != maxLinesOnPage)printf("\n%d:",LinesCounter+1);
            }
            else 
            {
                putchar(c);
                CharsCounter++;
            }
        }
        else
        {
            CharsCounter=0;
            LinesCounter++;
            if(LinesCounter != maxLinesOnPage)
            {
                printf("\n%d:",LinesCounter+1);
            }
            else
            {
                if(c != '\n')buf = c;
            }
        }
    }
    return 0;
}