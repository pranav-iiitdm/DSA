#include<stdio.h>
#include<stdlib.h>

struct tree 
{
    int data;
    struct tree * left;
    struct tree * right;
};


struct tree* newnode(int b);
struct tree * create_tree(struct tree * root,int x);

void preorder(struct tree * root);
void inorder(struct tree * root);
void postorder(struct tree * root);
struct tree * delete_node(struct tree * root,int x);
struct tree * min(struct tree * temp);

int main()
{
    int n,i,item,x;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    
    struct tree *root=NULL;

    int a[n];
    printf("Enter %d numbers \n",n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++)
    {
        root=create_tree(root,a[i]);
    }

    printf("Preorder is : \n");
    preorder(root);
    printf("\n");
    printf("Postorder is : \n");
    postorder(root);
    printf("\n");
    printf("Inorder is : \n");
    inorder(root);
    printf("\n");

    printf(" Enter the data for the node to be deleted \n");
    scanf("%d",&x);

    root=delete_node(root,x);
    
    printf("Preorder is : \n");
    preorder(root);
    printf("\n");
    printf("Postorder is : \n");
    postorder(root);
    printf("\n");
    printf("Inorder is : \n");
    inorder(root);
    printf("\n");

    return (0);
}

struct tree* newnode(int b)
{
    struct tree * ptr=(struct tree *)malloc(sizeof(struct tree));

    ptr->data=b;
    ptr->left=NULL;
    ptr->right=NULL;

    return (ptr);
}

struct tree * create_tree(struct tree * root,int x)
{
    if(root==NULL)
    {
        return (newnode(x));
    }

    else
    {
        if(root->data<x)
        {
            root->right=create_tree(root->right,x);
        }

        if(root->data>x)
        {
            root->left=create_tree(root->left,x);
        }

        return (root);
    }
}

void preorder(struct tree * root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tree * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct tree * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}

struct tree * min(struct tree * temp)
{
    struct tree * ptr=temp;

    while (ptr!=NULL && ptr->left!=NULL)
    {
        ptr=ptr->left;
    }

    return (ptr);
}

struct tree * delete_node(struct tree * root,int x)
{
    if(x<root->data)
    {
        root->left=delete_node(root->left,x);
    }
    
    else if(x>root->data)
    {
        root->right=delete_node(root->right,x);
    }

    else
    {
        if(root->left==NULL)
        {
            struct tree * temp=root;

            root=root->right;
            free(temp);
            return (root);
        }

        else if(root->right==NULL)
        {
            struct tree * temp1=root;

            root=root->left;
            free(temp1);
            return (root);
        }

        struct tree * temp=min(root->right);

        root->data=temp->data;

        root->right=delete_node(root->right,temp->data);
    }

    return (root);
}