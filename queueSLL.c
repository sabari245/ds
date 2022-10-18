/** implementation of queue in c using singly linked list */

#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to enqueue: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        struct node *temp = front;
        front = NULL;
        rear = NULL;
        printf("Dequeued value is %d", temp->data);
        free(temp);
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        printf("Dequeued value is %d", temp->data);
        free(temp);
    }
}

void isEmpty()
{
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is not empty");
    }
}

int main()
{
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Is Empty\n4. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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