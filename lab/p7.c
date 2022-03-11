#include <stdio.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
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
struct node * insertAtHead(struct node *head,int val)
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
}

struct node * insertAtTail(struct node *head,int val)
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
}

struct node *insertbefore(struct node *head,int val,int key)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    newnode->data=val;
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    return head;
};

struct node *nodeList(struct node *head)
{
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
void display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

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
    int index;
    int i=0;
    index=middle_position(head);
    while(i!=index)
    {
        i++;
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}

int main()
{
    int choice;
    int val;
    int n;
    int key;
    struct node *head=(struct node *)malloc(sizeof(struct node));
    while(1)
    {
        printf("\n1:NODE LIST ");
        printf("\n2:Insert at head");
        printf("\n3:Insert at tail");
        printf("\n4:Insert Before");
        printf("\n5:Display");
        printf("\n6:Delete Middle");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=nodeList(head);
            break;
        case 2:
            printf("\nEnter val: ");
            scanf("%d",&val);
            insertAtHead(head,val);
            break;
        case 3:
            printf("\nEnter val: ");
            scanf("%d",&val);
            insertAtTail(head,val);
            break;
        case 4:
            printf("\nEnter key: ");
            scanf("%d",&key);
            printf("\nEnter Val:");
            scanf("%d",&val);
            head=insertbefore(head,val,key);
            break;
        case 5:
            display(head);
            break;
        case 6:
            deleteMiddle(head);
            break;
        case 7:
            exit(1);
        }
    }
}
