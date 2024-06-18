#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

int count(node* head)
{
    int c = 0;
    node* ptr = head;
    while(ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}

node* AddToEmpty(node *head, int val)
{
    head = (node*)malloc(sizeof(node));
    head->prev = NULL;
    head->data = val;
    head->next = NULL;
    return head;
}

node* InsertAtBeginning(node *head, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

node* InsertAtEnd(node *head, int val)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;

    node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

node* InsertInBetween(node* head, int pos, int val)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;

    node* ptr = head;

    pos--;
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
 
    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
    temp->prev = ptr;
    
    return head;
}

void display(node* head)
{
    node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

node* CreateList(node* head)
{
    int n, val, i;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &n);

    if(n==0)
    {
        return head;
    }

    else
    {
        printf("Enter the element for node 1: ");
        scanf("%d", &val);
        head = AddToEmpty(head, val);

        for(i=1; i<n; i++)
        {
            printf("Enter the element for node %d: ", i+1);
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

    int op, val, c, pos;
    while(1)
    {
        printf("Enter 1 to Insert a node at beginning\n");
        printf("Enter 2 to Insert a node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to display the list\n");
        printf("Enter 5 to count the total nubmer of nodes in the list\n");
        printf("Enter 6 to exit\n");

        printf("Enter your option- ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            printf("Enter the element you want to enter at the beginning: ");
            scanf("%d", &val);
            head = InsertAtBeginning(head, val);
            break;

            case 2:
            printf("Enter the element you want to enter at the end: ");
            scanf("%d", &val);
            head = InsertAtEnd(head, val);
            break;

            case 3:
            printf("Enter the position at which you want to enter the element: ");
            scanf("%d", &pos);
            printf("Enter the element you want to enter: ");
            scanf("%d", &val);
            head = InsertInBetween(head, pos, val);
            break;

            case 4:
            display(head);
            break;

            case 5:
            c = count(head);
            printf("Total number of nodes in the list are: %d", c);
            break;

            case 6:
            exit(1);

            default:
            printf("Wrong input\n");
        }
    }

    return 0;
}