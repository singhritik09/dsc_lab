#include <stdio.h>
#define MAX 10

int top=-1;
int stack[MAX];

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isFull()
{
    if(top==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(int val)
{
    if(isFull())
    {
        printf("\nStack Overflow");
        return;
    }
    top++;
    stack[top]=val;
}

int pop()
{
    int val;
    if(isEmpty())
    {
        printf("\nStack Underflow");
        return;
    }
    val=stack[top];
    top--;
    return val;
}

void display()
{
    if(isEmpty())
    {
        printf("\nStack Is Empty");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
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
