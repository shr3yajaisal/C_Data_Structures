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

node* addition(node* head1, node* head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);

    node* ptr1 = head1;
    node* ptr2 = head2;
    node* head3 = NULL;

    int sum = 0, carry = 0;

    while (ptr1 != NULL || ptr2 != NULL || carry != 0) 
    {
        sum = carry;
        if (ptr1 != NULL) 
        {
            sum += ptr1->digit;
            ptr1 = ptr1->link;
        }
        if (ptr2 != NULL) 
        {
            sum += ptr2->digit;
            ptr2 = ptr2->link;
        }
        carry = sum / 10;
        sum = sum % 10;
        head3 = digit(head3, sum);
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

    printf("Sum of the numbers is: ");
    head3 = addition(head1, head2);
    print(head3);

    return 0;
}
