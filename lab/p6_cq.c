#include <stdio.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;
int isFull()
{
    if(front==rear+1||(front==rear+1 &&rear==MAX-1))
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

void enque(int val)
{
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
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    val=queue[front];
    front=(front+1)%MAX;
    return val;
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return;
    }
    for(int i=front;i<=front;i=(i+1)%MAX)
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
        printf("\n1:Enqueue");
        printf("\n2:Dequeue");
        printf("\n3:Display");
        printf("\n4:Exit");
        printf("\nEnter Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter value: ");
            scanf("%d",&val);
            enque(val);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}
