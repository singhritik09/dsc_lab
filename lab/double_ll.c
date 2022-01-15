#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;

struct node *insertAtHead(struct node *head,int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;

    return head;
};

struct node *insertAtTail(struct node *head,int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    newnode->data=val;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    newnode->prev=temp;

    return head;
};

struct node *createNode(struct node *head,int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    return head;
};

struct node *nodeList(struct node *head)
{
    struct node *newnode;
    struct node *temp;
    int n;
    int val;
    head=NULL;
    printf("\nEnter n: ");
    scanf("%d",&n);
    printf("\nEnter node: ");
    scanf("%d",&val);
    head=createNode(head,val);
    for(int i=1;i<n;i++)
    {
        printf("\nEnter value:");
        scanf("%d",&val);
        head=insertAtTail(head,val);
    }
    return head;
};

void display(struct node *head)
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\nList is Empty");
        return;
    }
    printf("NULL<-");
    while(temp!=NULL)
    {
        printf("<- %d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int middle_position()
{
    int count=0;
    struct node *temp=head;
    if(head==NULL)
    {
        count++;
    }
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count/2;
}

void delete_middle()
{
    struct node *temp;
    temp=head;
    int index=middle_position();
    int i=0;
    while(i!=index)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}

struct node *insertbefore(struct node *head,int key,int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    if(head==NULL || key<temp->data)
    {
        head=createNode(head,val);
    }
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    newnode->data=val;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;

    return head;

};

int main()
{
    int choice,val,key;
    //head=(struct node *)malloc(sizeof(struct node));
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
        delete_middle();
        break;
    case 4:
        printf("\nEnter key: ");
        scanf("%d",&key);
        printf("\nEnter value:");
        scanf("%d",&val);
        insertbefore(head,key,val);
        break;
    case 5:
        exit(1);
        }

    }
    return 0;
}
