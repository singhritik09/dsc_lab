#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next
};
struct node *head;
void insertAtHead()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    int val;
    printf("\nEnter value for head:");
    scanf("%d",&val);
    if(head==NULL)
    {
        head=newnode;
    }
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void insertAtTail()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    int val;
    printf("\nEnter value for tail:");
    scanf("%d",&val);
    newnode->data=val;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}

void nodeList()
{
    struct node *newnode;
    struct node *temp;
    int val;
    int n;
    printf("\nEnter Number of Nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter value for node %d:",i+1);
        scanf("%d",&val);
        if(head==NULL)
        {
            newnode->data=val;
            head=newnode;
            temp=head;
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
    printf("\n");
}

int deleteHead()
{
    struct node *temp=head;
    int val;
    val=temp->data;
    head=head->next;
    free(temp);
    return val;
}

int deleteTail()
{
    struct node *temp=head;
    struct node *temp2;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp;
    temp->next=NULL;
    free(temp2);
    return head;
}

int deleteVal()
{
    struct node *temp=head;
    struct node *temp2;
    int val;
    int key;
    printf("\nEnter value for deletion");
    scanf("%d",&val);
    if(val==temp->data)
    {
        deleteHead();
        return;
    }
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=temp->next->next;
    free(temp2);
    return head;
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

void insertAtIndex()
{
    int val;
    int index;
    int i=0;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter index:");
    scanf("%d",&index);
    printf("\nEnter Value: ");
    scanf("%d",&val);

    struct node *temp=head;
    while(i!=index-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
}

int main()
{
    int choice;
    int val;
    struct node *newnode;
    while(1)
    {
        printf("\nEnter 1 for creating nodes:");
        printf("\nEnter 2 to insert node at head:");
        printf("\nEnter 3 to insert node at tail:");
        printf("\nDelete node at head:4");
        printf("\nDelete node at tail:5");
        printf("\nEnter 6 to display linked list:");
        printf("\nEnter 7 to reverse linked list:");
        printf("\nEnter 8 to insert at index:");
        printf("\nEnter 9 to delete a value from linked list:");

        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=NULL;
            nodeList();
            break;
        case 2:
            insertAtHead();
            break;
        case 3:
            insertAtTail();
            break;
        case 4:
            deleteHead();
            break;
        case 5:
            deleteTail();
            break;
        case 6:
            display();
            break;
        case 7:
            reverseLL();
            break;
        case 8:
            insertAtIndex();
            break;
        case 9:
            deleteVal();
            break;
        case 10:
            exit(1);
        default:
            printf("\n************Wrong  Choice**************");
        }
    }
    return 0;
}
