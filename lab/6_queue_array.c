#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int front=-1;
int rear=-1;
int queue[MAX];
int isFull()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty()
{
    if(front==-1 || front ==rear+1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enque()
{
    int val;
    printf("\nEnter value for enqueue: ");
    scanf("%d",&val);
    if(isFull())
    {
        printf("\nQueue is full");
        return;
    }
    else{
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=val;
    }
}

int deque()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return;
    }
    else{
        int val=queue[front];
        front++;
        return val;
    }
}

void display()
{
    if(isEmpty())
    {
        printf("\Queue is Empty");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int peek()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return;
    }
    return queue[front];
}

int main()
{
    int choice;
    int val;
    while(1)
    {
        printf("\nEnter 1 for Enqueue:");
        printf("\nEnter 2 for Dequeue:");
        printf("\nEnter 3 for Peek:");
        printf("\nEnter 4 for Display:");
        printf("\nEnter 5 for Exit:");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            val=peek();
            printf("\nValue in front is %d",val);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("\nWrong Choice");
        }

    }

    return 0;
}
