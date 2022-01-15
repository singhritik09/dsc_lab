#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

void createNode(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;

}

void insertAtHead(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
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
    head=NULL;
    createNode(5);
    createNode(2);
    createNode(7);
    insertAtHead(3);
    display();
    return 0;
}
