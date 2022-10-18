/** implementation of polynomial ADT using singly linked list in c */

#include <stdio.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create()
{
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    struct node *head = NULL;
    struct node *temp = NULL;

    for (int i = 0; i <= degree; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &newNode->coeff);
        newNode->exp = i;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

struct node *add(struct node *head1, struct node *head2)
{
    struct node *head3 = NULL;
    struct node *temp = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (head1->exp == head2->exp)
        {
            newNode->coeff = head1->coeff + head2->coeff;
            newNode->exp = head1->exp;
            newNode->next = NULL;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->exp > head2->exp)
        {
            newNode->coeff = head1->coeff;
            newNode->exp = head1->exp;
            newNode->next = NULL;
            head1 = head1->next;
        }
        else
        {
            newNode->coeff = head2->coeff;
            newNode->exp = head2->exp;
            newNode->next = NULL;
            head2 = head2->next;
        }
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    while (head1 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coeff = head1->coeff;
        newNode->exp = head1->exp;
        newNode->next = NULL;
        head1 = head1->next;
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    while (head2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coeff = head2->coeff;
        newNode->exp = head2->exp;
        newNode->next = NULL;
        head2 = head2->next;
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head3;
}

struct node *subraction(struct node *head1, struct node *head2)
{
    struct node *head3 = NULL;
    struct node *temp = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (head1->exp == head2->exp)
        {
            newNode->coeff = head1->coeff - head2->coeff;
            newNode->exp = head1->exp;
            newNode->next = NULL;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->exp > head2->exp)
        {
            newNode->coeff = head1->coeff;
            newNode->exp = head1->exp;
            newNode->next = NULL;
            head1 = head1->next;
        }
        else
        {
            newNode->coeff = head2->coeff;
            newNode->exp = head2->exp;
            newNode->next = NULL;
            head2 = head2->next;
        }
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    while (head1 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coeff = head1->coeff;
        newNode->exp = head1->exp;
        newNode->next = NULL;
        head1 = head1->next;
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    while (head2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coeff = head2->coeff;
        newNode->exp = head2->exp;
        newNode->next = NULL;
        head2 = head2->next;
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head3;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
}

void main()
{
    struct node *head1 = create();
    struct node *head2 = create();
    struct node *head3 = add(head1, head2);
    struct node *head4 = subraction(head1, head2);
    printf("The first polynomial is: ");
    display(head1);
    printf("The second polynomial is: ");
    display(head2);
    printf("The sum of the two polynomials is: ");
    display(head3);
    printf("The difference of the two polynomials is: ");
    display(head4);
}