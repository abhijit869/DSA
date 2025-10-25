//stack operations in menu driven program
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push();
void pop();
void display();
int main(){
    int ch;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
void push(){
    int val;
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }else{
        printf("Enter the value to be pushed: ");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
        printf("%d pushed to stack\n",val);
    }
}
void pop(){
    int val;
    if(top==-1){
        printf("Stack Underflow\n");
    }else{
        val=stack[top];
        top=top-1;
        printf("%d popped from stack\n",val);
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }else{
        printf("Stack elements are: ");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}