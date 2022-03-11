#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
int isEmpty()
{
    if(front==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull()
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enque(int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("\nQueue is Full");
        return;
    }
    n->data=val;
    n->next=NULL;
    if(front==NULL)
    {
        front=n;
    }
    else{
        rear->next=n;
    }
    rear=n;
}

int deque()
{
    struct node *temp=front;
    int val;
    if(front==NULL)
    {
        printf("\nQueue is Empty");
        return;
    }
    val=temp->data;
    front=front->next;
    free(temp);
    return val;
}

void display()
{
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
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
