#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;

    return n;
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

struct node *inOrderpre(struct node *root)
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
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(val<root->data)
    {
        deleteNode(root->left,val);
    }
    else if(val>root->data)
    {
        deleteNode(root->right,val);
    }

    else{
        ipre=inOrderpre(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);
    }

    return root;
};

struct node *insert(struct node *root,int val)
{
    struct node *n;
    if(root==NULL)
    {
        return createnode(val);
    }
    if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=insert(root->right,val);
    }
    return root;
};
int main()
{
    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2=createnode(6);
    struct node *p3=createnode(1);
    struct node *p4=createnode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("\n");
    inorder(p);

    insert(p,11);
    printf("\n");
    inorder(p);
    //deleteNode(p,3);
    deleteNode(p,4);

    printf("\n");
    inorder(p);
}
