
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void nodeList(int n)
{
    struct node *newnode;
    struct node *temp;
    int i;
    int userinput;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&userinput);
        if(head==NULL)
        {
            newnode->data=userinput;
            head=newnode;
            temp=head;
        }
        else
        {
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
}

void deleteAtHead()
{
    struct node *temp=head;
    head=head->next;
    free(temp);
}

void reverseLL()
{
    struct node *prevptr=NULL;
    struct node *currptr=head;
    struct node *nextptr;

    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    head=prevptr;
}

int main()
{
    int n;
    struct node *newnode;
    int i,choice;
    printf("Enter 1 for input,2 for display,3 for delete at head,4 for reverse,5+ to exit:");
    scanf("%d",&choice);
    while(choice<5)
    {
        switch(choice)
        {
        case 1:
            head=NULL;
            nodeList(n);
            break;
        case 2:
            printf("Printing the linked list: \n");
            display();
            break;
        case 3:
            printf("Deleted the node at head: ");
            deleteAtHead();
            break;
        case 4:
            printf("\nReversed the linked list\n");
            reverseLL();
            break;
        }
        scanf("%d",&choice);
    }

    return 0;
}
