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
    int n;
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
void insertAtHead(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void insert()
{
    struct node *temp=head;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    int val;
    int key;
    printf("\nEnter value for insertion: ");
    scanf("%d",&val);

    key=val;
    newnode->data=val;
    if(head==NULL || key<temp->data)
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
    return 0;
}
