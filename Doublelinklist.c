#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    printf("Inserted %d at beginning\n", data);
}
void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted %d as first node\n", data);
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end\n", data);
}
void insertAtPosition(int data, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        insertAtBeginning(data);
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
        insertAtEnd(data);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, pos);
}
void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    if (temp->next == NULL)
    {
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("Deleted %d from end\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}
void deleteAtPosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (pos <= 1)
    {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Position not found\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}
void traversalForward()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void traversalBackward()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("Backward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void searchElement(int key)
{
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}
void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, data, pos, key;
    while (1)
    {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position\n7.Traversal Forward\n8.Traversal Backward\n9.Search Element\n10.Display\n11.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insertAtPosition(data, pos);
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 7:
            traversalForward();
            break;
        case 8:
            traversalBackward();
            break;
        case 9:
            printf("Enter element to search: ");
            scanf("%d", &key);
            searchElement(key);
            break;
        case 10:
            display();
            break;
        case 11:
            printf("Program ended.\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
