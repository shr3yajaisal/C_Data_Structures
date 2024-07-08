#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coefficient;
    int exponent;
    struct node* link;
}node;

node* insert(node* head, int coeff, int expo)
{
    node* temp = head;
    node* ptr = (node*)malloc(sizeof(node));
    ptr->coefficient = coeff;
    ptr->exponent = expo;
    ptr->link = NULL;

    if(head == NULL || expo > head->exponent)
    {
        ptr->link = head;
        head = ptr;
    }

    else
    {
        while(temp->link != NULL && temp->link->exponent > expo)
        {
            temp = temp->link;
        }
        ptr->link = temp->link;
        temp->link = ptr;
    }
    return head;
}

void simplification(node* head)
{
    node* temp = NULL;
    node* ptr = head;
    while(ptr->link != NULL)
    {
        if(ptr->exponent == ptr->link->exponent)
        {
            ptr->coefficient = ptr->coefficient + ptr->link->coefficient;
            temp = ptr->link;
            ptr->link = ptr->link->link; 
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr = ptr->link;
        }
    }
}

node* create (node* head)
{
    int n;
    int i;
    int coeff;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter the coefficient for term %d: ", i+1);
        scanf("%d", &coeff);
        printf("Enter the exponent for the term %d: ", i+1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    simplification(head);
    return head;
}

void display (node* head)
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
            printf("%dx^(%d)", ptr->coefficient, ptr->exponent);
            ptr = ptr->link;
            if(ptr != NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void PolyAddition (node* head1, node* head2)
{
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* head3 = NULL;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->exponent == ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }

        else if(ptr1->exponent > ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->link;
        }

        else if(ptr1->exponent < ptr2->exponent)
        {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->link;
    }
    simplification(head3);
    printf("Added polynomial is: ");
    display(head3);
}

void PolyMultiply (node* head1, node* head2)
{
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* head3 = NULL;

    if(head1 == NULL || head2 == NULL)
    {
        printf("0\n");
    }

    while(ptr1 != NULL)
    {
        while(ptr2 != NULL)
        {
            head3 = insert(head3, (ptr1->coefficient) * (ptr2->coefficient), (ptr1->exponent) + (ptr2->exponent));
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    simplification(head3);
    printf("Polynomial multiplication: ");
    display(head3);
}

int main()
{
    int op;

    node* head1 = (node*)malloc(sizeof(node));
    head1 = NULL;
    printf("Enter the first polynomial:\n"); 
    head1 = create(head1);
    display(head1);

    node* head2 = (node*)malloc(sizeof(node));
    head2 = NULL;
    printf("Enter the second polynomial:\n"); 
    head2 = create(head2);
    display(head2);

    while(1)
    {
        printf("Enter 1 to add the polynomials\n");
        printf("Enter 2 to multiply the polynomials\n");
        printf("Enter 3 to exit\n");

        printf("Enter your option: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            PolyAddition(head1, head2);
            break;

            case 2:
            PolyMultiply(head1, head2);
            break;

            case 3:
            exit(1);

            default:
            printf("Wrong input\n");
            break;
        }
    }

    return 0;
}
