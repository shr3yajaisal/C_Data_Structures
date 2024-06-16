#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;

node* AddToEmpty(node *head, int val)
{
    head = (node*)malloc(sizeof(node));
    head->data = val;
    head->link = NULL;
    return head;
}

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

node* InsertAtEnd(node *head, int val)
{
    node *ptr = head;
    node *temp;

    temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}

node* InsertAtBeginning(node *head, int val)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    ptr->link = head;
    head = ptr;

    return head;
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

node* DeleteList(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        free(temp);
        head = temp;
    }
    return head;
}

node* CreateList(node* head)
{
    int n, val;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    if(n == 0)
    {
        return head;
    }
    else
    {
        printf("Enter the value of node 1: ");
        scanf("%d", &val);
        head = AddToEmpty(head, val);

        for(int i=1; i<n; i++)
        {
            printf("Enter the value of node %d: ", i+1);
            scanf("%d", &val);
            head = InsertAtEnd(head, val);
        }
    }
    return head;
}

int main()
{
    node* head = (node*)malloc(sizeof(node));
    head = NULL;

    head = CreateList(head);

    int op, val;
    while(1)
    {
        printf("Enter 1 to Insert a node at beginning\n");
        printf("Enter 2 to Insert a node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to delete a node from the beginning\n");
        printf("Enter 5 to delete a node from the end\n");
        printf("Enter 6 to delete a node in between\n");
        printf("Enter 7 to delete the whole linked list\n");
        printf("Enter 8 to count the total nubmer of nodes in the list\n");
        printf("Enter 9 to display the list\n");
        printf("Enter 10 to exit\n");

        printf("Enter your option- ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            printf("Enter the value you want to enter at the beginning: ");
            scanf("%d", &val);
            head = InsertAtBeginning(head, val);
            break;

            case 2:
            printf("Enter the value you want to enter at the end: ");
            scanf("%d", &val);
            head = InsertAtEnd(head, val);
            break;

            case 3:
            InsertInBetween(head);
            break;

            case 4:
            DeleteFromBeginning(&head);
            break;

            case 5:
            DeleteFromEnd(head);
            break;

            case 6:
            DeleteInBetween(head);
            break;

            case 7:
            DeleteList(head);
            break;

            case 8:
            CountNodes(head);
            break;

            case 9:
            PrintData(head);
            break;

            case 10:
            exit(1);
            break;

            default:
            printf("Wrong input\n");
            break;
        }
    }
    
    return 0;
}
