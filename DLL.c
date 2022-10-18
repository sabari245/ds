/** implementation of doubly linked list in c */

#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

void insertAtBeginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
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
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtBeginning()
{
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void deleteAtEnd()
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;
    free(temp2);
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch;
    printf("1. Create\n2. Insert at beginning\n3. Insert at end\n4. Insert at position\n5. Delete at beginning\n6. Delete at end\n7. Delete at position\n8. Display\n9. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
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
}