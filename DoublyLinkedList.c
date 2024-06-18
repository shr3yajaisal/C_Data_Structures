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
    node* ptr = (node*)malloc(sizeof(node));
    ptr->prev = NULL;
    ptr->data = val;
    ptr->next = head;
    
    if(head != NULL)
    {
        head->prev = ptr;
    }
    head = ptr;
    
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

// METHON FOR INSERTION IN BETWEEN (USING ONE POINTER)
node* InsertInBetween(node* head, int pos, int val)
{
    int c = count(head);

    node *temp = (node*)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;

    node* ptr = head;

    if(pos == 1)
    {
        head = InsertAtBeginning(head, val);
    }

    else if(pos == c+1)
    {
        head = InsertAtEnd(head, val);
    }

    else
    {
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
    }
 
    return head;
}

/*ALTERNATIVE METHOD FOR INSERTION IN BETWEEN (USING TWO POINTERS)

node* InsertInBetween(node* head, int pos, int val)
{
    node* ptr = NULL;
    node* temp1 = head;
    node* temp2 = NULL;

    ptr = AddToEmpty(ptr, val);

    while(pos != 1)
    {
        temp1 = temp1->next;
        pos--;
    }

    if(temp1->next == NULL)
    {
        temp1->next = ptr;
        ptr->prev = temp1;
    }

    else if(pos == 1)
    {
        head = InsertAtBeginning(head, val);
    }

    else
    {
        temp2 = temp1->next;
        temp1->next = ptr;
        temp2->prev = ptr;
        ptr->next = temp2;
        ptr->prev = temp1;
    }

    return head;
}
*/

node* DeleteFromBeginning(node* head)
{
    if(head == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        node* ptr = head;
        head = head->next;
        free(ptr);
        ptr = NULL;
        head->prev = NULL;
    }
    return head;  
}

node* DeleteFromEnd(node* head)
{
    if(head == NULL)
    {
        printf("Linked list is already empty!");
    }
    else
    {
        node* ptr = head;
        while(ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
    return head;
}

node* DeletionInBetween(node* head, int pos)
{
    int c = count(head);

    if(pos == 1)
    {
        head = DeleteFromBeginning(head);
    }

    else if(pos == c)
    {
        head = DeleteFromEnd(head);
    }

    else
    {
        node* ptr1 = head;
        node* ptr2 = NULL;

        while(pos != 1)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            pos--;
        }
        ptr2->next = ptr1->next;
        free(ptr1);
        ptr1 = NULL;
        ptr2->next->prev = ptr2;
    }
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

    if(n == 0)
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

    c = count(head);

    while(1)
    {
        printf("Enter 1 to Insert a node at beginning\n");
        printf("Enter 2 to Insert a node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to delete the node from beginning\n");
        printf("Enter 5 to delete the node from the end\n");
        printf("Enter 6 to Delete the node in between\n");
        printf("Enter 7 to display the list\n");
        printf("Enter 8 to count the total nubmer of nodes in the list\n");
        printf("Enter 9 to exit\n");

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
            if(head == NULL)
            {
                printf("List is empty!\n");
            }
            else
            {
                printf("Enter the element you want to enter at the end: ");
                scanf("%d", &val);
                head = InsertAtEnd(head, val);
            }
            break;

            case 3:
            if(pos < 1 || pos > c)
            {
                printf("Invalid position!\n");
            }

            else
            {
                printf("Enter the position at which you want to enter the element: ");
                scanf("%d", &pos);
                printf("Enter the element you want to enter: ");
                scanf("%d", &val);
                head = InsertInBetween(head, pos, val);
            }  
            break;

            case 4:
            head = DeleteFromBeginning(head);
            break;

            case 5:
            head = DeleteFromEnd(head);
            break;

            case 6:
            printf("Enter the position from which you want to delete the node: ");
            scanf("%d", &pos);

            if(pos > c || pos < 1)
            {
                printf("Invalid position\n");
            }

            else
            {
                head = DeletionInBetween(head, pos);
            }
            break;

            case 7:
            display(head);
            break;

            case 8:
            c = count(head);
            printf("Total number of nodes in the list are: %d", c);
            break;

            case 9:
            exit(1);

            default:
            printf("Wrong input\n");
        }
    }

    return 0;
}
