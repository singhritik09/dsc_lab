#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createnode(struct node *head,int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    return head;
};

struct node *insertAtHead(struct node *head,int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
       head=newnode;
    }
    newnode->prev=NULL;
    newnode->next=head;
    head=newnode;

    return head;
};

int middle_position(struct node *head)
{
    int count = 0;
    if(head != NULL)
    {
        count++;
    }

    struct node *temp=head;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count/2;
}
struct node *insertbefore(struct node *head,int val,int key)
{
    struct node *newnode;
    struct node *temp,*p;
    newnode=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    p=temp;
    newnode->data=val;
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;

    return head;

};

void deleteMiddle(struct node *head)
{
    struct node *temp=head;
    int i=0;
    int index;
    index=middle_position(head);
    if(head==NULL)
    {
        printf("\nList is Empty");
    }
    while(i!=index)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}
struct node *insertAtTail(struct node *head,int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;

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
struct node *nodeList(struct node *head)
{
    struct node *newnode;
    struct node *temp;
    int n,val;
    head=NULL;
    printf("\nEnter n:");
    scanf("%d",&n);
    printf("\nEnter Element:");
    scanf("%d",&val);
    head=createnode(head,val);

    for(int i=1;i<n;i++)
    {
        printf("\nEnter element: ");
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
    }
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main()
{
    int choice,val,key;
    struct node *head=(struct node *)malloc(sizeof(struct node));
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
            deleteMiddle(head);
            break;
        case 4:
            printf("\nEnter key: ");
            scanf("%d",&key);
            printf("\nEnter value:");
            scanf("%d",&val);
            insertbefore(head,val,key);
            break;
        case 5:
            exit(1);

        }

    }
    return 0;
}
