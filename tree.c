#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree * root=NULL;

struct tree * binary_tree();
void preorder_traversal(struct tree * root);

int main()
{
    root=binary_tree();
    
    preorder_traversal(root);

    return (0);
}


struct tree * binary_tree()
{
    int x,ch;

    struct tree * newnode;
    newnode=(struct tree *)malloc(sizeof(struct tree));

    printf("Enter the data for new node \n");
    scanf("%d",&x);

    //newnode->data=x;

    if(x==0)
    return (0);

    else
    {
        newnode->data=x;

        printf("Insert the left branch for %d \n",x);
        newnode->left=binary_tree();

        printf("Insert the right branch for %d \n",x);
        newnode->right=binary_tree();
    }

    return (newnode);
}

void preorder_traversal(struct tree * root)
{
    if(root==NULL)
    {
        return;
    }

    
    preorder_traversal(root->left);
    printf(" %d ",root->data);

    preorder_traversal(root->right);
}