#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "lines.h"

void print(char ** array,int count);
void clearBuffer();
int maxLen(char **array,int count);
void InsertSort(char ***array,int count,int max,int length,int start);
void ShellSort(char ***array,int count);