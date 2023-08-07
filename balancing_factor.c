#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
};



struct tree * create_node(int x);
struct tree * create_bst(struct tree * node,int x);
void inorder(struct tree * root);
int height(struct tree * ptr);
void bal_factor(struct tree * temp);

int main()
{
    struct tree * root=NULL;
    
    int i,a,ch;
    
    for(i=0;ch!=2;i++)
    {
        printf("Enter \n 1. To insert data \n 2. To EXIT\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            printf("Enter the data to be inserted \n");
            scanf("%d",&a);
            
            root=create_bst(root,a);
            break;
        }
    }
    //inorder(root);
    //int z=height(root);
    //printf("  %d  \n",z);
    
    bal_factor(root);
    
    return (0);
}

struct tree * create_node(int x)
{
    struct tree * temp=(struct tree *)malloc(sizeof(struct tree));
    
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    
    return (temp);
}

struct tree * create_bst(struct tree * temp,int x)
{
    if(temp==NULL)
    return create_node(x);
    
    if(temp->data<x)
    temp->right=create_bst(temp->right,x);
    
    else
    temp->left=create_bst(temp->left,x);
    
    return (temp);
}

void inorder(struct tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

/*int height(struct tree * ptr)
{
    int lheight=1,rheight=1;
    
    if(ptr==NULL)
    {
        return (0);
    }
    
      lheight=height(ptr->left)+lheight;
      
      rheight=height(ptr->right)+rheight;
    
    if(lheight>=rheight)
    return(lheight);
    
    if(lheight<rheight)
    return(rheight);
}*/

int height(struct tree * ptr)
{
    if(ptr==NULL)
    {
        return (0);
    }

    int lheight=height(ptr->left);
    int rheight=height(ptr->right);

    if(lheight>rheight)
    return (lheight+1);

    else
    return (rheight+1);
}

void bal_factor(struct tree * temp)
{
    if(temp!=NULL)
    {
        printf(" B.F of node with value %d is %d \n",temp->data,(height(temp->left)-height(temp->right)));
        
        bal_factor(temp->left);
        bal_factor(temp->right);
    }
}