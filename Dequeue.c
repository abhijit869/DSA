//Dequeue operations in a menu-driven program
#include <stdio.h>  
#include <stdlib.h>
#define MAX 5
int deque[MAX];
int front = -1;
int rear = -1;
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display();
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
void insert_front()
{
    int item;
    if (front == 0 && rear == MAX - 1)
    {
        printf("Deque Overflow\n");
        return;
    }
    printf("Enter the item to be inserted at front: ");
    scanf("%d", &item);
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    deque[front] = item;
    printf("%d inserted at front\n", item);
}
void insert_rear()
{
    int item;
    if (front == 0 && rear == MAX - 1)
    {
        printf("Deque Overflow\n");
        return;
    }
    printf("Enter the item to be inserted at rear: ");
    scanf("%d", &item);
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = item;
    printf("%d inserted at rear\n", item);
}
void delete_front()
{
    int item;
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }
    item = deque[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    printf("%d deleted from front\n", item);
}
void delete_rear()
{
    int item;
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }
    item = deque[rear];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
    printf("%d deleted from rear\n", item);
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are: ");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", deque[i]);
    }
    else
    {
        for (i = front; i < MAX; i++)
            printf("%d ", deque[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", deque[i]);
    }
    printf("\n");
}