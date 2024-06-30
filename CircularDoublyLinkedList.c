#include <stdio.h>
#include <stdlib.h>

//creation of node
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

int count(node* tail)
{#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

int count(node* tail)
{
    int c = 0;
    if(tail == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        node* ptr = tail->next;
        c++;
        ptr = ptr->next;

        while(ptr != tail->next)
        {
            c++;
            ptr = ptr->next;
        }
    }
    return c;
}

node* InsertAtBeginning(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;

    if(tail == NULL)
    {
        temp->prev = temp;
        temp->next = temp;
        tail = temp;
    }

    else
    {
        node* ptr = tail->next;
        temp->prev = tail;
        temp->next = ptr;
        tail->next = temp;
        ptr->prev = temp;
    }
    return tail;
}

node* InsertAtEnd(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;

    if(tail == NULL)
    {
        printf("The linked list is already empty!\n");
    }
    else
    {
        node* ptr = tail->next;
        temp->prev = tail;
        temp->next = ptr;
        tail->next = temp;
        ptr->prev = temp;
        tail = temp;
    }
    return tail;
}

node* InsertInBetween(node* tail, int pos, int val)
{
    int c = count(tail);
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;

    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else if(pos == 1)
    {
        tail = InsertAtBeginning(tail, val);
    }
    else if(pos == c+1)
    {
        tail = InsertAtEnd(tail, val);
    }
    else
    {
        node* ptr = tail->next;
        pos--;
        while(pos != 1)
        {
            pos--;
            ptr = ptr->next;
        }
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;
    }
    return tail;
}

node* DeleteFromBeginning(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else
    {
        node* ptr = tail->next;
        tail->next = ptr->next;
        ptr->next->prev = tail;
        free(ptr);
        ptr = NULL;
    }
    return tail;
}

node* DeleteFromEnd(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else
    {
        node* ptr1 = tail->next;
        node* ptr2 = NULL;
        while(ptr1 != tail)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = tail->next;
        tail->next->prev = ptr2;
        free(ptr1);
        ptr1 = NULL;
        tail = ptr2;
    }
    return tail;
}

node* DeleteInBetween(node* tail, int pos)
{
    int c = count(tail);
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else if(pos == 1)
    {
        tail = DeleteFromBeginning(tail);
    }
    else if(pos == c)
    {
        tail = DeleteFromEnd(tail);
    }
    else
    {
        node* ptr1 = tail->next;
        node* ptr2 = NULL;
        while(pos != 1)
        {
            pos--;
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr1->next;
        ptr1->next->prev = ptr2;
        free(ptr1);
        ptr1 = NULL;
    }
    return tail;
}

void display(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is empty!\n");
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

    int c, op, val, pos;
    while(1)
    {
        printf("Enter 1 to Insert a node at the beginning\n");
        printf("Enter 2 to Insert a node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to delete the node from the beginning\n");
        printf("Enter 5 to delete the node from the end\n");
        printf("Enter 6 to delete the node in between two nodes\n");
        printf("Enter 7 to count the total number of nodes\n");
        printf("Enter 8 to print the linked list\n");
        printf("Enter 9 to exit\n");

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
            printf("Enter the value yuo want to insert at the end: ");
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
                printf("Enter the value you want to enter in between two nodes: ");
                scanf("%d", &val);
                tail = InsertInBetween(tail, pos, val);
            }
            break;

            case 4:
            tail = DeleteFromBeginning(tail);
            break;

            case 5:
            tail = DeleteFromEnd(tail);
            break;

            case 6:
            c = count(tail);
            printf("Enter the position from which you want to delete the node: ");
            scanf("%d", &pos);
            if(tail == NULL)
            {
                printf("Linked list is already empty!\n");
            }
            else if(pos < 1 || pos > c)
            {
                printf("Wrong position!\n");
            }
            else
            {
                tail = DeleteInBetween(tail, pos);
            }
            break;

            case 7:
            printf("Total number of nodes are: %d", count(tail));
            break;

            case 8:
            display(tail);
            break;

            case 9:
            exit(1);
            break;

            default:
            printf("Wrong input!\n");
            break;
        }
    }
    return 0;
}

    int c = 0;
    if(tail == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        node* ptr = tail->next;
        c++;
        ptr = ptr->next;

        while(ptr != tail->next)
        {
            c++;
            ptr = ptr->next;
        }
    }
    return c;
}

node* InsertAtBeginning(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;

    if(tail == NULL)
    {
        temp->prev = temp;
        temp->next = temp;
        tail = temp;
    }

    else
    {
        node* ptr = tail->next;
        temp->prev = tail;
        temp->next = ptr;
        tail->next = temp;
        ptr->prev = temp;
    }
    return tail;
}

node* InsertAtEnd(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;

    if(tail == NULL)
    {
        printf("The linked list is already empty!\n");
    }
    else
    {
        node* ptr = tail->next;
        temp->prev = tail;
        temp->next = ptr;
        tail->next = temp;
        ptr->prev = temp;
        tail = temp;
    }
    return tail;
}

node* InsertInBetween(node* tail, int pos, int val)
{
    int c = count(tail);
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;

    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else if(pos == 1)
    {
        tail = InsertAtBeginning(tail, val);
    }
    else if(pos == c+1)
    {
        tail = InsertAtEnd(tail, val);
    }
    else
    {
        node* ptr = tail->next;
        pos--;
        while(pos != 1)
        {
            pos--;
            ptr = ptr->next;
        }
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;
    }
    return tail;
}

node* DeleteFromBeginning(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else
    {
        node* ptr = tail->next;
        tail->next = ptr->next;
        ptr->next->prev = tail;
        free(ptr);
        ptr = NULL;
    }
    return tail;
}

node* DeleteFromEnd(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else
    {
        node* ptr1 = tail->next;
        node* ptr2 = NULL;
        while(ptr1 != tail)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = tail->next;
        tail->next->prev = ptr2;
        free(ptr1);
        ptr1 = NULL;
        tail = ptr2;
    }
    return tail;
}

node* DeleteInBetween(node* tail, int pos)
{
    int c = count(tail);
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else if(pos == 1)
    {
        tail = DeleteFromBeginning(tail);
    }
    else if(pos == c)
    {
        tail = DeleteFromEnd(tail);
    }
    else
    {
        node* ptr1 = tail->next;
        node* ptr2 = NULL;
        while(pos != 1)
        {
            pos--;
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr1->next;
        ptr1->next->prev = ptr2;
        free(ptr1);
        ptr1 = NULL;
    }
    return tail;
}

void display(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is empty!\n");
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

    int c, op, val, pos;
    while(1)
    {
        printf("Enter 1 to Insert a node at the beginning\n");
        printf("Enter 2 to Insert a node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to delete the node from the beginning\n");
        printf("Enter 5 to delete the node from the end\n");
        printf("Enter 6 to delete the node in between two nodes\n");
        printf("Enter 7 to count the total number of nodes\n");
        printf("Enter 8 to print the linked list\n");
        printf("Enter 9 to exit\n");

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
            printf("Enter the value yuo want to insert at the end: ");
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
                printf("Enter the value you want to enter in between two nodes: ");
                scanf("%d", &val);
                tail = InsertInBetween(tail, pos, val);
            }
            break;

            case 4:
            tail = DeleteFromBeginning(tail);
            break;

            case 5:
            tail = DeleteFromEnd(tail);
            break;

            case 6:
            c = count(tail);
            printf("Enter the position from which you want to delete the node: ");
            scanf("%d", &pos);
            if(tail == NULL)
            {
                printf("Linked list is already empty!\n");
            }
            else if(pos < 1 || pos > c)
            {
                printf("Wrong position!\n");
            }
            else
            {
                tail = DeleteInBetween(tail, pos);
            }
            break;

            case 7:
            printf("Total number of nodes are: %d", count(tail));
            break;

            case 8:
            display(tail);
            break;

            case 9:
            exit(1);
            break;

            default:
            printf("Wrong input!\n");
            break;
        }
    }
    return 0;
}
