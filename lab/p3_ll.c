#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

int isEmpty()
{
    if(top==NULL)
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

void push(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(isFull())
    {
        printf("\nStack Overflow");
        return;
    }
    newnode->data=val;
    newnode->next=top;
    top=newnode;
}

int pop()
{
    struct node *temp;
    temp=top;
    if(isEmpty())
    {
        printf("\nStack Underflow");
        return;
    }
    int val=temp->data;
    top=top->next;
    free(temp);
    return val;
}
int peek()
{
    if(isEmpty())
    {
        printf("\nStack Is empty");
        return;
    }
    return top->data;
}

void display()
{
    struct node *temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice,n;
    while(1)
    {
        printf("1:Push\n");
        printf("2:Pop\n");
        printf("3:Peek\n");
        printf("4:Display\n");
        printf("5:Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter value for push:");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            pop();
            break;

        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}
