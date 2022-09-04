#include <stdio.h>

#define MAX 10
#define receive(x, y)   \
    printf("%s > ", x); \
    scanf("%d", &y)

void create();
void insert();
void delete ();
void search();
void display();

int arr[MAX], n, i, j, item, pos;

int main()
{
    int ch;
    int flag = 1;
    printf("Menu\n\t0. Help\n\t1. Create\n\t2. Insert\n\t3. Delete\n\t4. Search\n\t5. Display\n\t6. Exit\n");
    do
    {
        receive("Choice", ch);
        switch (ch)
        {
        case 0:
            printf("Menu\n\t0. Help\n\t1. Create\n\t2. Insert\n\t3. Delete\n\t4. Search\n\t5. Display\n\t6. Exit\n");
            break;
        case 1:
            create();
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
            printf("[EXIT]\n");
            flag = 0;
            break;
        default:
            printf("[ERROR] Invalid choice\n\n");
        }
    } while (flag);
    return 0;
}

void create()
{
    receive("Create:Size", n);
    for (i = 0; i < n; i++)
    {
        receive("Create:Element", arr[i]);
    }
    printf("[SUCCESS] Array created\n\n");
}

void insert()
{
    receive("Insert:Position", pos);
    pos -= 1;
    if (pos < 0 || pos > n)
    {
        printf("[ERROR] Invalid position\n\n");
        return;
    }
    receive("Insert:Element", item);
    for (i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = item;
    n++;
    printf("[SUCCESS] Element inserted\n\n");
}

void delete ()
{
    receive("Delete:Position", pos);
    pos -= 1;
    if (pos < 0 || pos > n)
    {
        printf("[ERROR] Invalid position\n\n");
        return;
    }
    item = arr[pos];
    for (i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("[SUCCESS] Element Deleted: %d\n\n", item);
}

void search()
{
    receive("Search:Element", item);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            printf("[SUCCESS] Element found at position: %d\n\n", i + 1);
            return;
        }
    }
    printf("[ERROR] Element not found\n\n");
}

void display()
{
    printf("[INFO] Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}