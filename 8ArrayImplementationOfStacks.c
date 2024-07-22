#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int top = -1;
int stack[MAX];

void push(int data)
{
    if(top == MAX - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        top = top + 1;
        stack[top] = data;
    }
}

int pop()
{
    int value;
    if(top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        value = stack[top];
        top = top - 1;
    }
    return value;
}
