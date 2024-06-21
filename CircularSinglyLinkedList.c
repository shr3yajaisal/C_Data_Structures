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

int count(node* tail)
{
    int c = 0;
    if(tail == NULL)
    {
        return 0;
    }
    else
    {
        node* ptr = tail->link;
        c++;
        ptr = ptr->link;

        while(ptr != tail->link)
        {
            c++;
            ptr = ptr->link;
        }
    }
    return c;
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

node* InsertAtEnd(node* tail, int val)
{
    if(tail == NULL)
    {
        printf("Linked list is empty!\n");
    }

    else
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = val;
        temp->link = tail->link;
        tail->link = temp;
        tail = tail->link;
    }

    return tail;
}

node* InsertInBetween(node* tail, int pos, int val)
{
    int c = count(tail);

    if(pos == 1)
    {
        tail = InsertAtBeginning(tail, val);
    }
    else if(pos == c+1)
    {
        tail = InsertAtEnd(tail, val);
    }
    else
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = val;
        temp->link = NULL;

        node* ptr = tail->link;

        pos--;
        while(pos != 1)
        {
            ptr = ptr->link;
            pos--;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
    return tail;
}

int main()
{
    node* tail = (node*)malloc(sizeof(node));
    tail = NULL;

    int op, val, c, pos;
    while(1)
    {
        printf("Enter 1 to Insert a node at beginning\n");
        printf("Enter 2 to Insert the node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to count the number of nodes in the linked list\n");
        printf("Enter 5 to print the linked list\n");
        printf("Enter 6 to exit\n");

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
            printf("Enter the value you want to enter at the end: ");
            scanf("%d", &val);
            tail = InsertAtEnd(tail, val);
            break;

            case 3:
            c = count(tail);
            printf("Enter the position at which you want to insert the node: ");
            scanf("%d", &pos);
            if(pos < 1 || pos > c+1)
            {
                printf("Invalid position!\n");
            }
            else
            {
                printf("Enter the value you want to enter: ");
                scanf("%d", &val);
                tail = InsertInBetween(tail, pos, val);
            }
            break;

            case 4:
            c = count(tail);
            printf("Total number of nodes in the linked list are: %d\n", c);
            break;

            case 5:
            display(tail);
            break;

            case 6:
            exit(1);
            break;

            default:
            printf("Wrong input\n");
            break;
        }
    }
    return 0;
}
