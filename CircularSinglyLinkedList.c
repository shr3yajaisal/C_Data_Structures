#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}node;

node* AddToEmpty(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->link = temp;
    tail = temp;
    return tail;
}

node* InsertAtBeginning(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));

    if(tail == NULL)
    {
        temp->data = val;
        temp->link = temp;
        tail = temp;
    }
    else
    {
        temp->data = val;
        temp->link = NULL;
        temp->link = tail->link;
        tail->link = temp;
    }
    return tail; 
}

void display(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else
    {
        node* ptr = tail->link;
        printf("%d\n", ptr->data);
        ptr = ptr->link;

        while(ptr != tail->link)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
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
        printf("Enter 1 to Insert a node at beginning\n");
        printf("Enter 2 to print the linked list\n");
        printf("Enter 3 to exit\n");

        printf("Enter your option: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            printf("Enter the value to want to enter in the beginning: ");
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
            printf("Wrong input\n");
            break;
        }
    }
    return 0;
}
