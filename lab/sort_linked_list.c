#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void nodeList()
{
    struct node *temp;
    struct node *newnode;
    int val;
    int n;
    printf("\nEnter number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter data for node %d: ",i+1);
        scanf("%d",&val);
        if(head==NULL)
        {
            newnode->data=val;
            head=newnode;
            temp=newnode;
        }
        newnode->data=val;
        temp->next=newnode;
        temp=newnode;
    }
    temp->next=NULL;
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
}

void sort()
{
    struct node *p;
    struct node *q;
    p=head;
    for(p=head;p->next!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(p->data>q->data)
            {
                int temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter 1 to create linked list:");
        printf("\nEnter 2 to sort linked list:");
        printf("\nEnter 3 to display linked list:");
        printf("\nEnter 4 to exit:");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=NULL;
            nodeList();
            break;
        case 2:
            sort();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        }
    }

    return 0;
}
