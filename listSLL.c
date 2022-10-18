/** implementation of list singly linked list in c */
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    struct node *temp = NULL;
    for (int i = 0; i < size; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of element %d: ", i);
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
}

void insertBeginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void insertEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertMiddle()
{
    int pos;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &newNode->data);
    struct node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd()
{
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteMiddle()
{
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    struct node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

void search()
{
    int val;
    printf("Enter the value to search: ");
    scanf("%d", &val);
    struct node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            printf("Value found at position %d", i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("Value not found");
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    printf("1. Create\n2. Insert at beginning\n3. Insert at end\n4. Insert at middle\n5. Delete at beginning\n6. Delete at end\n7. Delete at middle\n8. Search\n9. Display\n10. Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertBeginning();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            insertMiddle();
            break;
        case 5:
            deleteBeginning();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteMiddle();
            break;
        case 8:
            search();
            break;
        case 9:
            display();
            break;
        case 10:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (choice != 10);
    return 0;
}