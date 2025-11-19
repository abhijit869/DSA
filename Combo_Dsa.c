/* Combo_Dsa.c: A program that implements Stack, Queue, and Linked List operations */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
int queue[MAX];
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

void enqueue()
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

void dequeue()
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
void create()
{
    struct Node *newNode, *temp;
    int n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d",&newNode->data);
        newNode->head=NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            temp=head;
            while(temp->head!=NULL){
                temp=temp->head;
            }
            temp->head=newNode;  
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
        printf("%d->", temp->data);
        temp = temp->head;
    }
    printf("NULL\n");
}

/* ---------------- MAIN PROGRAM ---------------- */
int main()
{
    int ch1, ch2, ch3;

    while (1)
    {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Linked List\n");
        printf("4. Exit\n");
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
                    enqueue();
                    break;
                case 2:
                    dequeue();
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
        case 3: /* Linked List menu */
            while (1)
            {
                printf("\n1.Create\n2.Insert at beginning\n3.Insert at end\n4.Insert at intermediate\n5.Delete from beginning\n6.Delete from end\n7.Delete from intermediate\n8.Display\n9.Back\n");
                printf("Enter your choice: ");
                scanf("%d", &ch3);
                switch (ch3)
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
                    goto end_linkedlist;
                default:
                    printf("Invalid choice\n");
                }
            }    
        end_linkedlist:
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
