#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
struct node * insertAtHead(struct node *head,int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return head;

}
struct node *createnode(struct node *head,int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    head=newnode;
    return head;
};
struct node * insertAtTail(struct node *head,int val)
{
    struct node *newnode,*p;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
    newnode->prev=p;

    return head;
};

struct node *nodeList(struct node *head)
{
    int val,n;
    printf("\nEnter Number of nodes:");
    scanf("%d",&n);
    head=NULL;
    printf("\nEnter Element: ");
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

void deleteMiddle(struct node *head)
{
    struct node *temp=head;
    struct node *p;
    int i=0;
    int index;
    index=middle_position(head);
    while(i!=index)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}

int main()
{
    int choice,val,key;
    struct node *head=(struct node *)malloc(sizeof(struct node));
    while(1)
    {
        printf("\n1:Create list");
        printf("\n2:Display");
        printf("\n3:Add to empty list");
        printf("\n4:Add to head");
        printf("\n5:Insert before");
        printf("\n6:Delete middle");
        printf("\nEnter your choice: ");
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
            printf("\nEnter Element for insertion:");
            scanf("%d",&val);
            head=createnode(head,val);
            break;
        case 4:
            printf("\nEnter data for head: ");
            scanf("%d",&val);
            head=insertAtHead(head,val);
            break;
        case 5:
            printf("\nEnter key: ");
            scanf("%d",&key);
            printf("\nEnter value:");
            scanf("%d",&val);
            insertbefore(head,val,key);
            break;
        case 6:
            deleteMiddle(head);
            break;

        }
    }

    return 0;
}
