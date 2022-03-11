#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createnode(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;
};

int getbalance(struct node *n)
{
    if(n==NULL)
    {
        return 0;
    }
    return getheight(n->left) -getheight(n->right);
}

