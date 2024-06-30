#include <stdio.h>
#include <stdlib.h>

//creation of node
typedef struct node
{
    int data;
    struct node* link;
}node;

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
        printf("Linked list is empty!\n");
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

node* DeleteFromBeginning(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is already empty!\n");
    }
    else
    {
        node* ptr = tail->link;
        tail->link = ptr->link;
        free(ptr);
        ptr = NULL;
    }

    return tail;
}

node* DeleteFromEnd(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is already Empty!\n");
    }
    else
    {
        node* ptr = tail;
        node* temp = tail->link;
        while(temp->link != tail)
        {
            temp = temp->link;
        }
        temp->link = ptr->link;
        free(ptr);
        ptr = NULL;
        tail = temp;
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
        node* ptr1 = tail->link;
        node* ptr2 = NULL;

        while(pos != 1)
        {
            ptr2 = ptr1;
            pos--;
            ptr1 = ptr1->link;
        }
        ptr2->link = ptr1->link;
        free(ptr1);
        ptr1 = NULL;
    }
    return tail;
}

void search(node* tail, int val)
{
    int c = 0;
    if(tail == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        node* ptr = tail->link;
        ptr = ptr->link;
        if(ptr->data == val)
        {
            c++;
        }

        while(ptr != tail->link)
        {
            ptr = ptr->link;
            if(ptr->data == val)
            {
                c++;
            }
        }
    }
    if(c == 0)
    {
        printf("The element is not in the linked list\n");
    }
    else
    {
        printf("Element found!\n");
    }
}

node* CreateList(node* tail)
{
    int n, val;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &n);

    if(n == 0)
    {
        return tail;
    }
    else
    {
        printf("Enter the value for node 1: ");
        scanf("%d", &val);
        tail = InsertAtBeginning(tail, val);

        for(int i=1; i<n; i++)
        {
            printf("Enter the value for node %d: ", i+1);
            scanf("%d", &val);
            tail = InsertAtEnd(tail, val);
        }
    }
    return tail;
}

int main()
{
    node* tail = (node*)malloc(sizeof(node));
    tail = NULL;
    tail = CreateList(tail);

    int op, val, c, pos;
    while(1)
    {
        printf("Enter 1 to Insert a node at beginning\n");
        printf("Enter 2 to Insert the node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to Delete the node from the beginning\n");
        printf("Enter 5 to delete the node form the end\n");
        printf("Enter 6 to delete the node in between two nodes\n");
        printf("Enter 7 to search an element in the list\n");
        printf("Enter 8 to count the number of nodes in the linked list\n");
        printf("Enter 9 to print the linked list\n");
        printf("Enter 10 to exit\n");

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
            tail = DeleteFromBeginning(tail);
            break;

            case 5:
            tail = DeleteFromEnd(tail);
            break;

            case 6:
            c = count(tail);
            printf("Enter the position from which you want to delete the node: ");
            scanf("%d", &pos);
            if(pos < 1 || pos > c)
            {
                printf("Invalid position!\n");
            }
            else
            {
                tail = DeleteInBetween(tail, pos);
            }
            break;

            case 7:
            printf("Enter the value you want to search in the linked list: ");
            scanf("%d", &val);
            search(tail, val);

            case 8:
            c = count(tail);
            printf("Total number of nodes in the linked list are: %d\n", c);
            break;

            case 9:
            display(tail);
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
