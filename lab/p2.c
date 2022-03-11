#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void nodeList(int n)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    int val;
    printf("\nEnter Nodes in ascending order");
    //head=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter node: ");
        scanf("%d",&val);
        if(head==NULL)
        {
            newnode->data=val;
            head=newnode;
            temp=newnode;

        }
        else{
            newnode->data=val;
            temp->next=newnode;
            temp=newnode;
        }
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
}

void insert(int val)
{
    struct node *temp=head;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(val<head->data||head==NULL)
    {
        newnode->data=val;
        newnode->next=head;
        head=newnode;
    }
    else{
    while(temp->next->data<val&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
    }
}

int main()
{
    int n,key;
    int val;
    int choice;
    while(1)
    {
        printf("\n1:Node LIST: ");
        printf("\n2:Insert in sorted: ");
        printf("\n3:Display");
        printf("\n4:Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter Number of nodes: ");
            scanf("%d",&n);
            nodeList(n);
            break;
        case 2:
            printf("\nEnter Val: ");
            scanf("%d",&val);
            insert(val);
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
