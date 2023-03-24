#include <stdio.h>
#include "Tasks.h"
#include "Input.h"
int main()
{
    int input;
    puts("\033[31mTask1: \033[0m");
    Task1();
    puts("\033[33mTask2: \033[0m");
    Task2();
    puts("\033[32mTask3: \033[0m");
    input = getchar();
    ClearBuffer();
    Task3(input);
    return 0;
}