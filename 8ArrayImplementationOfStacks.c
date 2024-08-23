#include <stdio.h>
#include <stdlib.h>
#define MAX 4


int stack[MAX];
int top = -1;

int IsFull()
{
    if(top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if(IsFull())
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
    
    if(IsEmpty()) 
    {
        printf("Stack underflow!\n");
    }
    int value;
    value = stack[top];
    top = top - 1;
    
    return value;
}

void print()
{
    int i;
    if(top == -1)
    {
        printf("Stack underflow!\n");
        return;
    }
    for(i=top; i>=0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main()
{
    int op, data;

    while(1)
    {
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to print the stack\n");
        printf("Enter 4 to exit\n");

        printf("Enter your option: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            printf("Enter the number you want to push: ");
            scanf("%d", &data);
            push(data);
            break;

            case 2:
            pop();
            break;

            case 3:
            print();
            break;

            case 4:
            exit(1);
            break;

            default:
            printf("Wrong input\n");
            break;
        }
    }
    return 0;
}
