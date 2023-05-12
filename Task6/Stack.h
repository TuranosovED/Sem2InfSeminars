#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "SortStructs.h"

void printStack(Stack *stack);
int Top(Stack *stack);
points Pop(Stack *stack);
void Push(Stack *stack, points value);