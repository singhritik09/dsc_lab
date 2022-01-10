#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

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
    struct stack *n=(struct stack *)malloc(sizeof(struct stack));
    if(n==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push()
{
    struct stack *n=(struct stack *)malloc(sizeof(struct stack));
    int val;
    printf("\nEnter data for push: ");
    scanf("%d",&val);
    if(isFull())
    {
        printf("\nStack Overflow");
        return;
    }
    n->data=val;
    n->next=top;
    top=n;

}

int pop()
{
    struct stack *temp=top;
    if(isEmpty())
    {
        printf("\nStack Underflow");
        return;
    }
    else{
        top=top->next;
        int val=temp->data;
        free(temp);
        return val;
    }
}

void display()
{
    struct stack *temp=top;
    if(isEmpty())
    {
        printf("\nStack Underflow");
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
        printf("\nStack Underflow");
        return;
    }
    return top->data;
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
