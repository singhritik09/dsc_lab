#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
};

struct node *inorderpre(struct node *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
};

struct node *deleteNode(struct node *root,int val)
{
    struct node *ipre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL &&root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(val<root->data)
    {
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteNode(root->right,val);
    }
    else
    {
        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);
    }
    return root;
};
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2=createnode(6);
    struct node *p3=createnode(1);
    struct node *p4=createnode(4);
    struct node *q;
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    inorder(p);
    printf("\n");

    deleteNode(p,3);
    inorder(p);
    return 0;
}
