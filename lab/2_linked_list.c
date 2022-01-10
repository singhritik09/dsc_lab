#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insertAtHead()
{
    struct node *temp;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    int val;
    printf("\nEnter data for head:");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void nodeList(int n)
{
    struct node *temp;
    struct node *newnode;

    int userinput;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&userinput);
        if(head==NULL)
        {
            newnode->data=userinput;
            head=newnode;
            temp=head;
        }
        else{
            newnode->data=userinput;
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
    printf("\n");
}

void insert()
{
    struct node *temp=head;
    struct node *newnode;
    int val;
    printf("\nEnter value for insertion in sorted order: ");
    scanf("%d",&val);
    newnode->data=val;

    int key=val;
    if(head==NULL || key<head->data)
    {
        newnode->next=head;
        head=newnode;
    }
    while(temp->next->data<key && temp->next!=NULL)
        {
            temp=temp->next;
        }
    newnode->next=temp->next;
    temp->next=newnode;
}

int main()
{
    head=(struct node *)malloc(sizeof(struct node));
    int choice,n;
    while(1)
    {
        printf("\nEnter 1 to add node at end:");
        printf("\nEnter 2 to insert in ascending order:");
        printf("\nEnter 3 to display linked list:");
        printf("\nEnter 4 to exit:");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        printf("\n************ENTER NODES IN ASCENDING ORDER**********\n");
        head=NULL;
        nodeList(n);
        break;
        case 2:
            insert();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\n***********Wrong Choice*********");
            break;
        }
    }
}
