#include <stdio.h>
#include <stdlib.h>

int List[100];
int ListSize = 0;

void createList()
{
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    ListSize = size;

    for (int i = 0; i < ListSize; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &List[i]);
    }
}

void insert()
{
    int pos, val;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    printf("Enter the value to insert: ");
    scanf("%d", &val);

    for (int i = ListSize; i >= pos; i--)
    {
        List[i] = List[i - 1];
    }
    List[pos] = val;
    ListSize++;
}

void delete ()
{
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    for (int i = pos; i < ListSize; i++)
    {
        List[i] = List[i + 1];
    }
    ListSize--;
}

void search()
{
    int val;
    printf("Enter the value to search: ");
    scanf("%d", &val);

    for (int i = 0; i < ListSize; i++)
    {
        if (List[i] == val)
        {
            printf("Value found at position %d", i);
            return;
        }
    }
    printf("Value not found");
}

void display()
{
    printf("The list is: ");
    for (int i = 0; i < ListSize; i++)
    {
        printf("%d ", List[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("1. Create List\n2. Insert\n3. Delete\n4. Search\n5. Display\n6. Exit\n");
    while (1)
    {
        printf("enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}