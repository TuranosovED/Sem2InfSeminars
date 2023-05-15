#include <stdio.h>
#include <stdlib.h>
#include "lines.h"
#define asc 0
#define desc 1

typedef struct Root
{
    struct Root *leftChildren;
    struct Root *rightChildren;
    int count;
    char* str;
}Root;

int CompareStr(char *s1,char *s2,int key)//1 - s1 > s2 ; 2 - s2 > s1 ; 3 - равны ; // key 0 - ask , key 1 - desc
{
    if((int)s1[0] > (int)s2[0])
        return 2 - key;
    else if((int)s1[0] < (int)s2[0])
        return 1 + key;
    else
    {
        for(int i =0;(s1[i] !='\0') || (s2[i] !='\0');i++)
        {
            if(s1[i] == '\0')return 1 + key;
            if(s2[i] == '\0')return 2 - key;
            if((int)s1[i] > (int)s2[i])return 2 - key;
            else if((int)s1[i] < (int)s2[i])return 1 + key;
        }
    }
    return 3;
}
    

Root* AddRoot(char *s)//выделение вершины
{
    Root *object = (Root*)malloc(sizeof(Root));
    object->str = s;
    object->leftChildren = NULL;
    object->rightChildren = NULL;
    object->count = 1;
    return object;
}

Root* AddChildren(Root* Parent,char*s,int key)//добавление дочерних вершин
{
    if(CompareStr(s,(Parent->str),key) == 1) // Parent > s
    {
        if(Parent->leftChildren == NULL)
        {
            Parent->leftChildren = AddRoot(s);
        }
        else
        {
            AddChildren(Parent->leftChildren,s,key);
        }
    }
    else if(CompareStr(s,(Parent->str),key) == 2) //parent < s
    {
        if(Parent->rightChildren == NULL)
        {
            Parent->rightChildren = AddRoot(s);
        }
        else
        {
            AddChildren(Parent->rightChildren,s,key);
        }
    }
    else if(CompareStr(s,(Parent->str),key) == 3)
        Parent->count++;
}

void PrintTree(Root *root)
{
    if(root->leftChildren != NULL)
    {
        PrintTree(root->leftChildren);
    }
    if(root->rightChildren != NULL) 
    {
        PrintTree(root->rightChildren);  
    }
    printf("%s ",root->str);
}

void SortTree(Root *root) //left - сверху - от меньшего к большему right - сверху от большего к меньшему
{
    if(root->leftChildren!=NULL)
    {
        SortTree(root->leftChildren);
    }
    printf("%s %d\n",root->str,root->count);
    if(root->rightChildren !=NULL)
    {
        SortTree(root->rightChildren);
    }
}

int CheakArguments(char **s)
{
    char key1[] = "asc";
    char key2[] = "desc";
    char keyO[] = "-o";
    int trigger = 0;

    if(s[2] == NULL)
        return asc;
    
    for(int i =0;i<s[2][i]!='\0';i++)
    {
        if(s[2][i] != keyO[i])
            trigger = 1;
    }

    if((trigger == 1 ) || (len(keyO) != len(s[2])))
        return -1;

    if(s[3] == NULL)
        return -1;

    for(int i =0;s[3][i]!='\0';i++)
    {
        if(s[3][i] != key1[i])
            trigger = 1;
    }

    if((trigger == 0) && (len(key1) == len(s[3])))
        return asc;

    trigger = 0;

    for(int i =0; s[3][i] !='\0';i++)
    {
        if(s[3][i] != key2[i])
            trigger = 1;
    }
     if((trigger == 0) && (len(key2) == len(s[3])))
        return desc;
    else
        return -1;
}

int main(int argc, char* argv[])
{
    FILE *f = fopen(argv[1],"r");
    if(f == NULL)
    {
        puts("File not founded!");
        return 0;
    }
    int key = CheakArguments(argv);
    if(key < 0)
    {
        puts("Error, unknown arguments!");
        return 0;
    }
    
    Root *root;
    char c;
    char *line = NULL;
    int counter;
    int trigger = 0; //тригер на 1 строку, чтобы сделать ее корнем
    for(counter =0; (c = fgetc(f)) != EOF;)
    {
        if(c != '\n')
            PushLine(&line,c,counter++);
        else
        {
            PushLine(&line,'\0',counter);
            if(trigger == 0)
            {
                root = AddRoot(line);
                trigger++;
            }
            else 
                AddChildren(root,line,key);
            counter = 0;
            line = NULL;
        }
    }

    PushLine(&line,'\0',counter);
    AddChildren(root,line,key);

    SortTree(root);

    return 0;
}