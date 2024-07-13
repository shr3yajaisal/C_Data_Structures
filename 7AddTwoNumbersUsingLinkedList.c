#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int digit;
    struct node* link;
}node;

node* digit(node* head, int dig)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->digit = dig;
    temp->link = NULL;

    temp->link = head;
    head = temp;
    return head;
}

node* reverse(node* head)
{
    if(head == NULL)
    {
        return head;
    }
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

node* addition(node* head1, node* head2)
{
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* head3 = NULL;

    int sum = 0, carry = 0;

    while(ptr1 != NULL || ptr2 != NULL)
    {

        sum = 0;
        if(ptr1 == NULL)
        {
            sum = 0;
        }
        else
        {
            sum = sum + ptr1->digit;
        }
        if(ptr2 == NULL)
        {
            sum = 0;
        }
        else
        {
            sum = sum + ptr2->digit;
        }
        sum = sum + carry;
        carry = 0;
        carry = sum/10;
        sum = sum%10;;
        head3 = digit(head3, sum);
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }
    return head3;
}

void print(node* head)
{
    node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d", ptr->digit);
        if(ptr->link != NULL)
        {
            printf("->");
        }
        ptr = ptr->link;
    }
}

int main()
{
    int n1, n2;

    node* head1 = (node*)malloc(sizeof(node));
    head1 = NULL;

    node* head2 = (node*)malloc(sizeof(node));
    head2 = NULL;

    node* head3 = (node*)malloc(sizeof(node));
    head3 = NULL;

    printf("Enter the first number: ");
    scanf("%d", &n1);

    printf("Enter the second number: ");
    scanf("%d", &n2);

    while(n1 != 0)
    {
        head1 = digit(head1, n1%10);
        n1 = n1/10;
    }
    print(head1);
    printf("\n");

    while(n2 != 0)
    {
        head2 = digit(head2, n2%10);
        n2 = n2/10;
    }
    print(head2);
    printf("\n");

    return 0;
}
