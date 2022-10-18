/** implementation of queue in c using array */

#include <stdio.h>

int Queue[100];
int QueueSize = 0;

void enqueue()
{
    if (QueueSize == 100)
    {
        printf("Queue is full");
    }
    else
    {
        int val;
        printf("Enter the value to enqueue: ");
        scanf("%d", &val);
        Queue[QueueSize] = val;
        QueueSize++;
    }
}

void dequeue()
{
    if (QueueSize == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        int val = Queue[0];
        for (int i = 0; i < QueueSize; i++)
        {
            Queue[i] = Queue[i + 1];
        }
        QueueSize--;
        printf("Dequeued value is %d", val);
    }
}

void isEmpty()
{
    if (QueueSize == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is not empty");
    }
}

void isFull()
{
    if (QueueSize == 100)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Queue is not full");
    }
}

void main()
{
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Is Empty\n4. Is Full\n5. Exit\n");
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
            isFull();
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice");
            break;
        }
        printf("\n");
    } while (choice != 5);
    return 0;
}