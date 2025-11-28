/*-------- Combo_Dsa.c: A program that implements Stack, Queue, and Linked List operations ------------------*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
int queue[MAX];
int deque[MAX];
int priority[MAX];
int front = -1, rear = -1;
struct Node
{
    int data;
    struct Node *head;
};
struct Node *head = NULL;
void push()
{
    int x;
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
    printf("%d pushed\n", x);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped\n", stack[top]);
    top--;
}

void display_stack()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void enqueue1()
{
    int x;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &x);
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = x;
    printf("%d enqueued\n", x);
}

void dequeue1()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display_queue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
void enqueue2()
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
void dequeue2()
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
void display_CircularQueue()
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
void display_deque()
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
void enqueue3()
{
    int item, prio, i, j;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the item to be enqueued: ");
    scanf("%d", &item);
    printf("Enter its priority (lower number means higher priority): ");
    scanf("%d", &prio);
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = item;
    priority[rear] = prio;
    // Rearranging based on priority
    for (i = front; i < rear; i++)
    {
        for (j = i + 1; j <= rear; j++)
        {
            if (priority[i] > priority[j])
            {
                // Swap priorities
                int tempPrio = priority[i];
                priority[i] = priority[j];
                priority[j] = tempPrio;
                // Swap corresponding items
                int tempItem = queue[i];
                queue[i] = queue[j];
                queue[j] = tempItem;
            }
        }
    }
    printf("%d enqueued to queue with priority %d\n", item, prio);
}
void dequeue3()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    item = queue[front];
    printf("%d dequeued from queue\n", item);
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display_priorityqueue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements with their priorities:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("Item: %d, Priority: %d\n", queue[i], priority[i]);
    }
}
/*----------Single Linked List-------------------*/
void create()
{
    struct Node *newNode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data:");
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
void display1()
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
        printf("%d->", temp->data);
        temp = temp->head;
    }
    printf("NULL\n");
}

/*------------Circular Linked List-------------------*/
void create1()
{
    struct Node *newNode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d", &newNode->data);
        newNode->head = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->head = head; // Point to itself
        }
        else
        {
            temp = head;
            while (temp->head != head)
            {
                temp = temp->head;
            }
            temp->head = newNode;
            newNode->head = head; // Maintain circularity
        }
    }
}
void insertAtBeginning()
{
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = newNode;
        newNode->head = head; // Point to itself
    }
    else
    {
        temp = head;
        while (temp->head != head)
        {
            temp = temp->head;
        }
        temp->head = newNode;
        newNode->head = head;
        head = newNode; // Update head to new node
    }
}
void insertAtEnd()
{
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = newNode;
        newNode->head = head; // Point to itself
    }
    else
    {
        temp = head;
        while (temp->head != head)
        {
            temp = temp->head;
        }
        temp->head = newNode;
        newNode->head = head; // Maintain circularity
    }
}
void insertAtIntermediate()
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
        insertAtBeginning();
        return;
    }
    temp = head;
    while (i < pos - 1 && temp->head != head)
    {
        temp = temp->head;
        i++;
    }
    if (temp->head == head && i < pos - 1)
    {
        printf("Position not found\n");
    }
    else
    {
        newNode->head = temp->head;
        temp->head = newNode;
    }
}
void deleteBeginning()
{
    struct Node *temp, *last;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->head == head)
    {
        free(head);
        head = NULL;
        return;
    }
    last = head;
    while (last->head != head)
    {
        last = last->head;
    }
    temp = head;
    head = head->head;
    last->head = head; // Maintain circularity
    free(temp);
}
void deleteEnd()
{
    struct Node *temp, *prev;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->head == head)
    {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->head != head)
    {
        prev = temp;
        temp = temp->head;
    }
    prev->head = head; // Maintain circularity
    free(temp);
}
void deleteAtintermediate()
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
        deleteBeginning();
        return;
    }
    temp = head;
    while (i < pos && temp->head != head)
    {
        prev = temp;
        temp = temp->head;
        i++;
    }
    if (temp->head == head && i < pos)
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
    do
    {
        printf("%d->", temp->data);
        temp = temp->head;
    } while (temp != head);
    printf("(head)\n");
}


/* ---------------- MAIN PROGRAM ---------------- */
int main()
{
    int ch1, ch2, ch3, ch4, ch5, ch6, ch7;

    while (1)
    {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Circular Queue\n");
        printf("4. Dequeue\n");
        printf("5. Prarity Queue\n");
        printf("6. Linked List\n");
        printf("7. Circular Linked List\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1: /* Stack menu */
            while (1)
            {
                printf("\n--- STACK MENU ---\n");
                printf("1. Push\n2. Pop\n3. Display\n4. Back\n");
                printf("Enter choice: ");
                scanf("%d", &ch2);

                switch (ch2)
                {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display_stack();
                    break;
                case 4:
                    goto end_stack;
                default:
                    printf("Invalid\n");
                }
            }
        end_stack:
            break;
        case 2: /* Queue menu */
            while (1)
            {
                printf("\n--- QUEUE MENU ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
                printf("Enter choice: ");
                scanf("%d", &ch2);

                switch (ch2)
                {
                case 1:
                    enqueue1();
                    break;
                case 2:
                    dequeue1();
                    break;
                case 3:
                    display_queue();
                    break;
                case 4:
                    goto end_queue;
                default:
                    printf("Invalid\n");
                }
            }
        end_queue:
            break;
        case 3: /* Circular Queue menu */
            while (1)
            {
                printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &ch3);
                switch (ch3)
                {
                case 1:
                    enqueue2();
                    break;
                case 2:
                    dequeue2();
                    break;
                case 3:
                    display_CircularQueue();
                    break;
                case 4:
                    goto end_circularqueue;
                default:
                    printf("Invalid choice\n");
                }
            }
        end_circularqueue:
            break;
        case 4:
            while (1)
            {
                printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Back\n");
                printf("Enter your choice:");
                scanf("%d", &ch4);
                switch (ch4)
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
                    display_deque();
                    break;
                case 6:
                    goto end_dequeue;
                default:
                    printf("Invalid choice\n");
                }
            }
        end_dequeue:
            break;
        case 5:
            while (1)
            {
                printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Back\n");
                printf("Enter your choice:");
                scanf("%d", &ch5);
                switch (ch5)
                {
                case 1:
                    enqueue3();
                    break;
                case 2:
                    dequeue3();
                    break;
                case 3:
                    display_priorityqueue();
                    break;
                case 4:
                    goto end_priorityqueue;
                default:
                    printf("Invalid choice\n");
                }
            }
        end_priorityqueue:
            break;
        case 6:
            /* Linked List menu */
            while (1)
            {
                printf("\n1.Create\n2.Insert at beginning\n3.Insert at end\n4.Insert at intermediate\n5.Delete from beginning\n6.Delete from end\n7.Delete from intermediate\n8.Display\n9.Back\n");
                printf("Enter your choice: ");
                scanf("%d", &ch6);
                switch (ch6)
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
                    display1();
                    break;
                case 9:
                    goto end_linkedlist;
                default:
                    printf("Invalid choice\n");
                }
            }
        end_linkedlist:
            break;
        case 7:
            while (1)
            {
                printf("\n====== Circular Linked List Menu ======\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Delete from Beginning\n");
                printf("4. Delete from End\n");
                printf("5. Display\n");
                printf("6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &ch7);

                switch (ch7)
                {
                case 1:
                    create1();
                    break;
                case 2:
                    insertAtBeginning();
                    break;
                case 3:
                    insertAtEnd();
                    break;
                case 4:
                    insertAtIntermediate();
                    break;
                case 5:
                    deleteBeginning();
                    break;
                case 6:
                    deleteEnd();
                    break;
                case 7: 
                    deleteAtintermediate();
                    break;
                case 8:
                    display();    
                    goto end_circularlinkedlist;
                default:
                    printf("Invalid choice!\n");
                }
            }
        end_circularlinkedlist:
            break;
        case 8:
            printf("#------------Programme terminated!------------#\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
