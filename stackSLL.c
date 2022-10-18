/** implementation of stack using singly linked list in c */

#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to push: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void pop()
{
    if (head == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void isEmpty()
{
    if (head == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack is not empty");
    }
}

int main()
{
    int choice;
    printf("1. Push\n2. Pop\n3. Is Empty\n4. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (choice != 4);
    return 0;
}
