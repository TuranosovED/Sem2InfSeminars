#include <stdio.h>
#include <stdlib.h>
#include "lines.h"

typedef struct City
{
    char* name;
    int PeopleCount;
    struct City* next;
}City;

int hash(char *key,int capacity)
{
    int sum = 0;
    for(int i=0;key[i]!='\0';i++)
        sum+=key[i];
    return sum%capacity;
}

int CompareStr(char *s1,char*s2)
{
    for(int i =0;(s1[i] !='\0') && (s2[i] !='\0');i++)
        if(s1[i] != s2[i])return -1;
    return 1;
}

void DeleteElement(City **HashTable,char* str,int capacity)//так как список односвязный то возвращаю на 1 элемент левее
{
    int key = hash(str,capacity);
    City **head;
    City*buffer;
    int trigger = 0;
    if(HashTable[key] == NULL)
    {
        puts("Element not founded!");
    }
    else
    {
        head = &HashTable[key];
        if(((*head)->next) == NULL)
        {
            if(CompareStr((*head)->name,str) > 0)
            {
                free((*head));
                HashTable[key] = NULL;
                puts("Complete!");
            }
            else puts("Element not founded!");
        }
        else if(CompareStr((*head)->name,str) > 0)
        {
            buffer = (*head)->next;
            free((*head));
            (*head) = buffer;
            puts("Complete!");
        }
        else
        {
            while(CompareStr((*head)->next->name,str) < 0)
            {
                printf("%s ",(*head)->next->name);
                head = &((*head)->next);
                if((*head)->next == NULL)
                {
                    trigger = 1;
                    break;
                }
            }
            if(trigger)
            {
                puts("Element not founded!");
            }
            else
            {
                buffer = (*head)->next->next;
                if(buffer == NULL)
                {
                    //printf("%s %s\n",(*head)->name,(*head)->next->name);
                    (*head)->next = NULL;
                    free((*head)->next);
                }
                else
                {
                    free((*head)->next);
                    (*head)->next = buffer;
                }
                puts("Complete!");
            }
            
        }
    }
}

int PushInTable(City**HashTable,City value,int capacity)
{
    int key = hash(value.name,capacity);
    for(City *head = HashTable[key];head != NULL;head = head->next)
    {
        if(CompareStr(head->name,value.name) > 0)return 1;
    }
    City *object = (City*)malloc(sizeof(City));
    object->next = HashTable[key];
    object->name = value.name;
    object->PeopleCount = value.PeopleCount;
    HashTable[key] = object;
}

City MakeCityValue()
{
    char *s;
    int CountOfPeople;
    puts("enter name of city: ");
    s = EnterStr();
    puts("enter count of people: ");
    scanf("%d",&CountOfPeople);
    return (City){s,CountOfPeople,NULL};
}

void PrintHashTable(City **HashTable,int capacity)
{
    for(int i =0;i<capacity;i++)
    {
        printf("%d: ",i);
        for(City *head = HashTable[i];head!=NULL;)
        {
            printf("%s %d ",head->name,head->PeopleCount);
            head = head->next;
        }
        putchar('\n');
    }
}

City **InitHashTable(int capacity)
{
    City **HashTable = (City**)malloc(sizeof(City*) * capacity);
    for(int i =0;i<capacity;i++)
        HashTable[i] = NULL;
    return HashTable;
}

int main()
{
    int capacity;
    puts("enter capacity of hash table: ");
    scanf("%d",&capacity);
    while(capacity <= 0)
    {
        system("cls");
        puts("try again please");
        scanf("%d",&capacity);
    }
    
    
    City **HashTable = InitHashTable(capacity);
    City *Buffer;
    int command;
    while(1)
    {
        system("cls");
        puts("1 - enter element in table\n2 - print table\n3 - delete element\n4 - exit\n");
        scanf("%d",&command);
        switch (command)
        {
        case 1:
            PushInTable(HashTable,MakeCityValue(),capacity);
            break;
        case 2:
            PrintHashTable(HashTable,capacity);
            system("pause");
            break;
        case 3:
            DeleteElement(HashTable,EnterStr(),capacity);
            system("pause");
            break;
        case 4:
            return 0;
        default:
            puts("Unknown command, try again.");
            system("pause");
        }
    }
    
}