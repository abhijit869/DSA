//singlelinklist operations
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *head;
};
struct Node *head = NULL;
void create();
void insert_begin();
void insert_end();
void insert_intermediate();
void delete_begin();
void delete_end();
void delete_intermediate();
void display();
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Create\n2.Insert at beginning\n3.Insert at end\n4.Insert at intermediate\n5.Delete from beginning\n6.Delete from end\n7.Delete from intermediate\n8.Display\n9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_intermediate();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_intermediate();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
void create()
{
    struct Node *newNode, *temp;
    int choice = 1;
    while (choice)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->head = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->head != NULL)
            {
                temp = temp->head;
            }
            temp->head = newNode;
        }
        printf("Do you want to continue (0/1)? ");
        scanf("%d", &choice);
    }
}
void insert_begin()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->head = head;
    head = newNode;
}
void insert_end()
{
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->head = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->head != NULL)
        {
            temp = temp->head;
        }
        temp->head = newNode;
    }
}
void insert_intermediate()
{
    struct Node *newNode, *temp;
    int pos, i = 1;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->head = NULL;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        newNode->head = head;
        head = newNode;
        return;
    }
    temp = head;
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->head;
        i++;
    }
    if (temp == NULL)
    {
        printf("Position not found\n");
    }
    else
    {
        newNode->head = temp->head;
        temp->head = newNode;
    }
}
void delete_begin()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->head;
    free(temp);
}
void delete_end()
{
    struct Node *temp, *prev;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->head == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->head != NULL)
    {
        prev = temp;
        temp = temp->head;
    }
    prev->head = NULL;
    free(temp);
}
void delete_intermediate()
{
    struct Node *temp, *prev;
    int pos, i = 1;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp = head;
        head = head->head;
        free(temp);
        return;
    }
    temp = head;
    while (i < pos && temp != NULL)
    {
        prev = temp;
        temp = temp->head;
        i++;
    }
    if (temp == NULL)
    {
        printf("Position not found\n");
    }
    else
    {
        prev->head = temp->head;
        free(temp);
    }
}
void display()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("List elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->head;
    }
    printf("\n");
}

