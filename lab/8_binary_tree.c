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
void  inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node *insert(struct node *root,int val)
{
    struct node *newnode;
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

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int height(struct node *root)
{
    int hleft,hright;
    if(root==NULL)
    {
        return 0;
    }
    hleft=height(root->left);
    hright=height(root->right);

    if(hleft>hright)
    {
        return 1+hleft;
    }
    else{
        return 1+hright;
    }

}

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
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);

    insert(p,11);
    printf("\n");
    inorder(p);
}
