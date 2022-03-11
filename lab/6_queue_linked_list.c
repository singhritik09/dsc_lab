#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
}*front=NULL,*rear=NULL;

int isEmpty()
{
    if(front==NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct queue *n=(struct queue *)malloc(sizeof(struct queue));
    if(n==NULL)
    {
        return 1;
    }
    return 0;
}

void enque()
{
    int val;
    struct queue *newnode=(struct queue *)malloc(sizeof(struct queue));
    printf("\nEnter Value for Enque: ");
    scanf("%d",&val);
    if(isFull())
    {
        printf("\nQueue is Full");
        return;
    }
    if(front==NULL)
    {
        front=newnode;
    }
    else{
        rear->next=newnode;
    }
    newnode->data=val;
    newnode->next=NULL;
    rear=newnode;

}

int deque()
{
    struct queue *temp=front;
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return;
    }
    int val=temp->data;
    front=front->next;
    free(temp);
    return val;
}

void display()
{
    struct queue *temp=front;
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
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
    return front->data;
}

int main()
{int choice;
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
