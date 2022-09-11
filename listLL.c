/* implementation of list ADT using linked list */
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void create();
void insert();
void del();
void search();
void display();

int main()
{
    int ch;
    int flag = 1;
    printf("Menu\n\t0. Help\n\t1. Create\n\t2. Insert\n\t3. Delete\n\t4. Search\n\t5. Display\n\t6. Exit\n");
    do
    {
        printf("Choice > ");
        scanf("%d", &ch);
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
            del();
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
    int n, i, item;
    printf("Create:Size > ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Create:Element > ");
        scanf("%d", &item);
        struct node *link = (struct node *)malloc(sizeof(struct node));
        link->data = item;
        link->next = NULL;
        if (head == NULL)
        {
            head = link;
            current = link;
        }
        else
        {
            current->next = link;
            current = link;
        }
    }
}

void insert()
{
    int item, pos, i;
    printf("Insert:Element > ");
    scanf("%d", &item);
    printf("Insert:Position > ");
    scanf("%d", &pos);
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = item;
    link->next = NULL;
    if (pos == 0)
    {
        link->next = head;
        head = link;
    }
    else
    {
        struct node *temp = head;
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        link->next = temp->next;
        temp->next = link;
    }
}

void del()
{
    int pos, i;
    printf("Delete:Position > ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        struct node *temp = head;
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void search()
{
    int item, i = 0;
    printf("Search:Element > ");
    scanf("%d", &item);
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("[FOUND] %d at %d position\n", item, i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("[NOT FOUND] %d\n", item);
    return;
}

void display()
{
    struct node *temp = head;
    printf("[DISPLAY] ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}