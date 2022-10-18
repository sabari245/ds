/** implementation of stack data structure using array in c */

#include <stdio.h>

int Stack[100];
int StackSize = 0;

void push()
{
    if (StackSize == 100)
    {
        printf("Stack is full");
    }
    else
    {
        int val;
        printf("Enter the value to push: ");
        scanf("%d", &val);
        Stack[StackSize] = val;
        StackSize++;
    }
}

void pop()
{
    if (StackSize == 0)
    {
        printf("Stack is empty");
    }
    else
    {
        StackSize--;
    }
}

void isEmpty()
{
    if (StackSize == 0)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack is not empty");
    }
}

void isFull()
{
    if (StackSize == 100)
    {
        printf("Stack is full");
    }
    else
    {
        printf("Stack is not full");
    }
}

void main()
{
    int choice;
    printf("1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Exit\n");
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
            isFull();
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (choice != 5);
}