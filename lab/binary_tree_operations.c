#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
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

struct node *insert(struct node *root,int val)
{
    struct node *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(val==root->data)
        {
            return;
        }
        else if(val<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node *n=createNode(val);
    if(val<prev->data)
    {
        prev->left=n;
    }
    else{
        prev->right=n;
    }
    return n;
};

struct node *inOrderpre(struct node *root)  //LEFT SUBTREE'S RIGHTMOST CHILD
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

    //SEARCH FOR NODE TO BE DELETED
    if(val<root->data)
    {
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=deleteNode(root->right,val);
    }
    else{
        ipre=inOrderpre(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);
    }

    return root;
};

int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);

    if(lheight>rheight)
    {
        return lheight+1;
    }
    else{
        return rheight+1;
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
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
int max(struct node *root)
{
    struct node *temp=root;
    if(root==NULL)
    {
        return NULL;
    }
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }

    return temp->data;
}

int min(struct node *root)
{
    struct node *temp=root;
    if(root==NULL)
    {
        return NULL;
    }
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}

int rootNode(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    return root->data;
}
int main()
{
    struct node *p=createNode(5);
    struct node *p1=createNode(3);
    struct node *p2=createNode(6);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    inorder(p);
    printf("\n");
    deleteNode(p,3);
    deleteNode(p,5);
    insert(p,11);
    printf("\nHeight of tree: %d \n",height(p));
    inorder(p);
    printf("\n");
    printf("Max value: %d",max(p));
    printf("\n");
    printf("Min value: %d",min(p));
    printf("\n");
    printf("Root node value: %d",rootNode(p));
    return 0;
}


