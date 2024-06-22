#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* InsertAtBeginning(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    if(tail == NULL)
    {
        temp->data = val;
        temp->prev = temp;
        temp->next = temp;
    }
    else
    {
        node* ptr = tail->next;
        temp->data = val;
        temp->prev = tail;
        temp->next = ptr;
        tail->next = temp;
    }
    return tail;
}

void display(node* tail)
{
    if(tail == NULL)
    {
        printf("Lnked list is empty!\n");
    }
    else
    {
        node* ptr = tail->next;
        printf("%d\n", ptr->data);
        ptr = ptr->next;

        while(ptr != tail->next)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    node* tail = (node*)malloc(sizeof(node));
    tail = NULL;

    int op, val;
    while(1)
    {
        printf("Enter 1 to Insert a node at the beginning\n");
        printf("Enter 2 to print the linked list\n");
        printf("Enter 3 to exit\n");

        printf("Enter your option: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            printf("Enter the value you want to insert at the beginning: ");
            scanf("%d", &val);
            tail = InsertAtBeginning(tail, val);
            break;

            case 2:
            display(tail);
            break;

            case 3:
            exit(1);
            break;

            default:
            printf("Wrong input!\n");
        }
    }
}
