#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}node;

node* AddToEmpty(int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->link = temp;
    return temp;
}

node* InsertAtBeginning(node* tail, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->link = tail->link;
    tail->link = temp;

    return tail; 
}

void display(node* tail)
{
    if(tail == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        node* ptr = tail;

        while(ptr->link != tail)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
       printf("%d\n", ptr->data);
    }
}

int main()
{
    node* tail = (node*)malloc(sizeof(node));
    tail = NULL;

    tail = AddToEmpty(25);
    tail = InsertAtBeginning(tail, 26);
    tail = InsertAtBeginning(tail, 27);
    tail = InsertAtBeginning(tail, 28);
    tail = InsertAtBeginning(tail, 29);
    display(tail);
    return 0;
}
