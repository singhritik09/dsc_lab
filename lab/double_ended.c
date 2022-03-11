#include <stdio.h>
#define MAX 10

int front=-1;
int rear=-1;
int queue[MAX];
void enque_front(int val)
{
    if(isFull())
    {
        printf("\nQueue is FULL");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0)
    {
        front=MAX-1;
    }
    else{
        front=front-1;
    }
    queue[front]=val;
}

void enque_rear(int val)
{
    if(isFull())
    {
        printf("\nQueue is Full");
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==MAX-1)
    {
        rear=0;
    }
    else{
        rear=rear+1;
    }
    queue[rear]=val;
}

int isFull()
{
    if((front==0&&rear==MAX-1)||(front==rear+1))
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty()
{
    if(front==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void display()
{
    int i;
    i=front;
    if(front<=rear)
    {
        while(i<=rear)
        {
            printf("%d ",queue[i]);
            i++;
        }
    }
    else{
        while(i<=MAX-1)
        {
            printf("%d ",queue[i]);
            i++;
        }
        i=0;
        while(i<=rear){
            printf("%d ",queue[i]);
            i++;
        }
    }
}
int main()
{
    int choice;
    int val;
    while(1)
    {
        printf("\n1:ENQUE FRONT");
        printf("\n2:ENQUE REAR");
        printf("\n3:DEQUE FRONT");
        printf("\n4:DEQUE REAR");
        printf("\n5:DISPLAY");
        printf("\n6:EXIT");
        printf("\nENTER CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter val: ");
            scanf("%d",&val);
            enque_front(val);
            break;
        case 2:
            printf("\nEnter val: ");
            scanf("%d",&val);
            enque_rear(val);
            break;

        case 5:
            display();
            break;
        case 6:
            exit(1);
        }
    }
    return 0;
}
