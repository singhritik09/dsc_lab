#include <stdio.h>
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
    if(front==-1||front==rear+1)
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
    else{
            if(front==-1)
            {
                front=0;
            }
        rear=(rear+1)%MAX;
        queue[rear]=val;
    }
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
        val=queue[front];
        front++;
    }
    return val;
}
void display()
{
    int val;
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
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
