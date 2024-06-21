#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* AddToEmpty(int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->prev = temp;
    temp->next = temp;
    return temp; 
}