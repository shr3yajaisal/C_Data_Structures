#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;

node* AddToEmpty(node *head, int val){
    head = (node*)malloc(sizeof(node));
    head->data = val;
    head->link = NULL;
    return head;
}

int CountNodes(node *head){
    int count = 0;
    node *ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }

    return count;
}

void PrintData(node *head){
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

node* InsertAtEnd(node *head, int val){
    node *ptr = head;
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}

node* InsertAtBeginning(node *head, int val){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    ptr->link = head;
    head = ptr;

    return head;
}

node* InsertInBetween(node *head, int pos, int val){
    int c = CountNodes(head);

    node *ptr = head;
    node *ptr2 = (node*)malloc(sizeof(node));
    ptr2->data = val;
    ptr2->link = NULL;

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
            ptr = ptr->link;
            pos--;
        }
        ptr2->link = ptr->link;
        ptr->link = ptr2;
    }
    return head;
}

node* InsertionInSorted(node* head, int val){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    int key = val;
    temp->link = NULL;

    node* ptr = head;

    if(head == NULL || key < head->data)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        while(ptr->link != NULL && ptr->link->data < key)
        {
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
    return head;
}

void DeleteFromBeginning(node **head){
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

void DeleteFromEnd(node *head){
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

void DeleteInBetween(node* head){
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

node* DeleteList(node* head){
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        free(temp);
        head = temp;
    }
    return head;
}

node* CreateList(node* head){
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

node* ReversingList(node* head){
    node *prev = NULL;
    node* next = NULL;

    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main(){
    node* head = (node*)malloc(sizeof(node));
    head = NULL;

    head = CreateList(head);

    int c, op, val, pos;
    while(1)
    {
        printf("Enter 1 to Insert a node at beginning\n");
        printf("Enter 2 to Insert a node at the end\n");
        printf("Enter 3 to Insert a node in between two nodes\n");
        printf("Enter 4 to Insert an element in the sorted sinlgy linked list\n");
        printf("Enter 5 to delete a node from the beginning\n");
        printf("Enter 6 to delete a node from the end\n");
        printf("Enter 7 to delete a node in between\n");
        printf("Enter 8 to delete the whole linked list\n");
        printf("Enter 9 to reverse the linked list\n");
        printf("Enter 10 to count the total nubmer of nodes in the list\n");
        printf("Enter 11 to display the list\n");
        printf("Enter 12 to exit\n");

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
            printf("Enter the position at which you want to enter the element: ");
            scanf("%d", &pos);
            if(pos < 1 || pos > c)
            {
                printf("Invalid position!\n");
            }

            else
            {
                printf("Enter the element you want to enter: ");
                scanf("%d", &val);
                head = InsertInBetween(head, pos, val);
            }  
            break;

            case 4:
            printf("Enter the value you want to insert: ");
            scanf("%d", &val);
            head = InsertionInSorted(head, val);
            break;

            case 5:
            DeleteFromBeginning(&head);
            break;

            case 6:
            DeleteFromEnd(head);
            break;

            case 7:
            DeleteInBetween(head);
            break;

            case 8:
            DeleteList(head);
            break;

            case 9:
            head = ReversingList(head);
            break;

            case 10:
            c = CountNodes(head);
            printf("Total number of node are: %d\n", c);
            break;

            case 11:
            PrintData(head);
            break;

            case 12:
            exit(1);
            break;

            default:
            printf("Wrong input\n");
            break;
        }
    }
    
    return 0;
}
