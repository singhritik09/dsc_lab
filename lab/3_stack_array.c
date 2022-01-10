#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int top=-1;
int stack[MAX];

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

void push()
{
    int val;
    printf("\nEnter Value for Push: ");
    scanf("%d",&val);

    if(isFull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    else{
        top++;
        stack[top]=val;
    }
}

int pop()
{
    if(isEmpty())
    {
        printf("\nStack Underflow");
        return;
    }
    int val=stack[top];
    top--;
    return val;
}

int peek()
{
    if(isEmpty())
    {
        printf("\nStack Undeflow");
        return;
    }
    return stack[top];
}
void display()
{
    if(isEmpty())
    {
        printf("\nStack Underflow");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf(" %d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    int val;
    while(1)
    {
        printf("\nEnter 1 for push:");
        printf("\nEnter 2 for pop:");
        printf("\nEnter 3 for display:");
        printf("\nEnter 4 for peek:");
        printf("\nEnter 5 for exit:");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            val=peek();
            printf("\nValue at top: %d",val);
            break;
        case 5:
            exit(1);
        default:
            printf("\n********************Wrong Choice******************");
        }
    }

    return 0;
}
