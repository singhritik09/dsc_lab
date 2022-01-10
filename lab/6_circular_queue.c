#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

int isFull()
{
    if(front==rear+1 ||(front ==rear+1  && rear==MAX-1))
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty()
{
    if(front==-1)
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
    printf("\nEnter value for enqueue:");
    scanf("%d",&val);
    if(isFull())
    {
        printf("\nQueue is Full");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%MAX;
    queue[rear]=val;
}

int deque()
{
    int val;
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return;
    }
    else{
    if(front==rear)
    {
        front = -1;
        rear = -1;
    }
    else
        {
        val=queue[front];
        front=(front+1)%MAX;
        }
    return (val);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return;
    }
    for(int i=front;i<=rear;i=(i+1)%MAX)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    int val;
    while(1)
    {
        printf("\nEnter 1 for enqueue:");
        printf("\nEnter 2 for dequeue:");
        printf("\nEnter 3 for display:");
        printf("\nEnter 4 for exit:");
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
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("**********Wrong Choice*******\n");
        }
    }
    return 0;
}
