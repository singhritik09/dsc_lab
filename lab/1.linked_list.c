#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node * nodeList(int n)
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
    return head;
}

void deleteAtHead()
{
    struct node *temp=head;
    free(temp);
    head=head->next;
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

int main()
{
    head=(struct node *)malloc(sizeof(struct node));
    int choice,n;
    while(1)
    {
        printf("\nEnter 1 to add node at end:");
        printf("\nEnter 2 to delete node at head:");
        printf("\nEnter 3 to display linked list:");
        printf("\nEnter 4 to exit:");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        head=NULL;
        nodeList(n);
        break;
        case 2:
            deleteAtHead();
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
