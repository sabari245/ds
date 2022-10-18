/** implementation of circular linked list in c */

#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
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
    temp->next = head;
}

void insertAtBeginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    struct node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning()
{
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
}

void deleteAtEnd()
{
    struct node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    temp->next = head;
}

void deleteAtPosition()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void display()
{
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int main()
{
    int choice;
    printf("1. Create\n2. Insert at beginning\n3. Insert at end\n4. Insert at position\n5. Delete at beginning\n6. Delete at end\n7. Delete at position\n8. Display\n9. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            deleteAtPosition();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}