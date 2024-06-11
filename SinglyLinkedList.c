#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;

void CountNodes(node *head)
{
    int count = 0;
    if(head == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        node *ptr = head;
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
        printf("Total number of node are: %d\n", count);
    }
}

void PrintData(node *head)
{
    if(head == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        node *ptr = head;
        while(ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void InsertAtEnd(node *head)
{
    int val;
    node *ptr = head;
    node *temp;

    temp = (node*)malloc(sizeof(node));
    printf("Enter the value you want to enter at the end: ");
    scanf("%d", &val);
    temp->data = val;
    temp->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void InsertAtBeginning(node **head)
{
    int val;
    printf("Enter the value you want to enter at the beginning: ");
    scanf("%d", &val);

    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    ptr->link = *head;
    *head = ptr;
}

void InsertInBetween(node *head)
{
    int val, pos;
    printf("Enter the value you want to enter in between: ");
    scanf("%d", &val);
    printf("Enter the position at which you want to enter the element: ");
    scanf("%d", &pos);

    node *ptr = head;
    node *ptr2 = (node*)malloc(sizeof(node));
    ptr2->data = val;
    ptr2->link = NULL;

    pos--;
    while(pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

void DeleteFromBeginning(node **head)
{
    if(head == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else
    {
        node *temp = *head;
        *head = (*head)->link;
        free(temp);
        temp = NULL;
    }
}

void DeleteFromEnd(node *head)
{
    if(head == NULL)
    {
        printf("Linked list is already empty!");
    }

    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }

    else
    {
        node *temp1 = head;
        node *temp2 = NULL;
        while(temp1->link != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->link;
        }
        temp2->link = NULL;
        free(temp1);
        temp1 = NULL;
    } 
}

void DeleteInBetween(node* head)
{
    int pos;
    node *ptr1 = head;
    node *ptr2 = NULL;

    printf("Enter the position from which you want to delete the element: ");
    scanf("%d", &pos);

    if(head == NULL)
    {
        printf("Linked list is already empty!");
    }

    else
    {
        while(pos != 1)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->link;
            pos--;
        }
        ptr2->link = ptr1->link;
        free(ptr1);
        ptr1 = NULL;
    }
}

int main()
{
    node *head = (node*)malloc(sizeof(node));
    head->data = 23;
    head ->link = NULL;

    node *current = (node*)malloc(sizeof(node));
    current->data = 54;
    current->link = NULL;
    head->link = current;

    current = (node*)malloc(sizeof(node));
    current->data = 78;
    current->link = NULL;
    head->link->link = current;

    current = (node*)malloc(sizeof(node));
    current->data = 62;
    current->link = NULL;
    head->link->link->link = current;

    CountNodes(head);

    PrintData(head);

    InsertAtEnd(head);
    printf("After inserting at the end:\n");
    PrintData(head);

    InsertAtBeginning(&head);
    printf("After inserting at the beginning:\n");
    PrintData(head);

    InsertInBetween(head);
    printf("After inserting in between:\n");
    PrintData(head);

    DeleteFromBeginning(&head);
    printf("After deleting from the beginning:\n");
    PrintData(head);

    DeleteFromEnd(head);
    printf("After deleting from the end:\n");
    PrintData(head);

    DeleteInBetween(head);
    printf("After deleting from between:\n");
    PrintData(head);

    return 0;
}
