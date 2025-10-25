#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
void enque();
void deque();
void display();
int main(){
    int ch;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                enque();
                break;
            case 2:
                deque();
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
}
void enque(){
    int val;
    if(rear == MAX - 1){
        printf("Queue Overflow\n");
    } else {
        printf("Enter the value to be enqueued: ");
        scanf("%d",&val);
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = val;
        printf("%d enqueued to queue\n", val);
    }
}
void deque(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
    } else {
        int val = queue[front];
        front++;
        printf("%d dequeued from queue\n", val);
    }
}
void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

