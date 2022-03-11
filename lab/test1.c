#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
struct node *createnode(struct node *head,int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;
    n->prev=NULL;
    head=n;
    return head;
};

struct node *insertAtHead(struct node *head,int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->prev=NULL;
    n->next=NULL;
    head=n;

    return head;
};

struct node *insertAtTail(struct node *head,int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    n->data=val;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
    n->prev=temp;

    return head;
};

struct node * nodeList(struct node *head)
{
    struct node *newnode;
    struct node *temp;
    int val;
    int n;
    head=NULL;
    printf("\nEnter number of nodes:");
    scanf("%d",&n);
    printf("\nEnter node 1:");
    scanf("%d",&val);
    head=createnode(head,val);
    for(int i=1;i<n;i++)
    {
        printf("\nEnter data for node %d: ",i+1);
        scanf("%d",&val);
        head=insertAtTail(head,val);
    }
    return head;
}

int middle_position(struct node *head)
{
    int count=0;
    struct node *temp=head;
    if(head==NULL)
    {
        count++;
    }
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    return count/2;
}

void deleteMiddle(struct node *head)
{
    struct node *temp;
    int i=0;
    int index=middle_position(head);
    while(i!=index)
    {
        temp=temp->next;
        i++;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
}

void display(struct node *head)
{
    struct node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice,val,key;
    //=(struct node *)malloc(sizeof(struct node));
    while(1)
    {
        printf("\n1:Create list");
        printf("\n2:Display");
        printf("\n3:Delete Middle");
        printf("\n4:Insert Before");
        printf("\n5:Exit");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=nodeList(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            //deleteMiddle(head);
            break;
        case 4:
            printf("\nEnter key: ");
            scanf("%d",&key);
            printf("\nEnter value:");
            scanf("%d",&val);
            //insertbefore(head,val,key);
            break;
        case 5:
            exit(1);

        }

    }
    return 0;
}

