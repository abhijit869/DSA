//circular queue operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
void enqueue()
{
    int item;
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the item to be enqueued: ");
    scanf("%d", &item);
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    printf("%d enqueued to queue\n", item);
}
void dequeue()
{
    int item;
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    item = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    printf("%d dequeued from queue\n", item);
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}