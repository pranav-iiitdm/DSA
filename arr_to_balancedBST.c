#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree * root=NULL;

struct stack
{
    struct tree * loc;
    struct stack * next;
};

struct stack * top=NULL;

struct tree * create_node(int x);
struct tree * create_tree(int min,int max,int a[]);
void push(struct tree * ptr);
struct tree * pop();
void inorder(struct tree * root);

int main()
{
    int n,i;
    printf("Enter the no.of integers \n");
    scanf("%d",&n);
    
    int a[n];
    printf("Enter %d integers \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    root=create_tree(0,n,a);
    
    inorder(root);
    
    return (0);
}

struct tree * create_node(int x)
{
    struct tree * ptr=(struct tree *)malloc(sizeof(struct tree));
    
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;
    
    return (ptr);
}

struct tree * create_tree(int min,int max,int a[])
{
    struct tree * temp=NULL;
    
    int i=(min+max)/2;
    if(min>max)
    return (temp);
    else
    {
        temp=create_node(a[i]);
        temp->left=create_tree(min,i-1,a);
        temp->right=create_tree(i+1,max,a);
        
        return (temp);
    }
    
    
}

void inorder(struct tree* ptr)
{   
    int flag=1;
    
    while(flag)
    {
        if(ptr)
        {
            push(ptr);
            ptr=ptr->left;
        }
        
        else
        {
            if(top!=NULL)
            {
                ptr=pop();
                printf("%d ",ptr->data);
                ptr=ptr->right;
            }
            
            else
            {
                flag=0;
            }
        }
        
    }
}   

/*void inorder(struct tree * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}*/

void push(struct tree * ptr)
{
    struct stack * temp=(struct stack *)malloc(sizeof(struct stack));

    if(top==NULL)
    {
        temp->loc=ptr;
        temp->next=NULL;
        top=temp;
    }

    else
    {
        temp->loc=ptr;
        temp->next=top;
        top=temp;
    }
}

struct tree * pop()
{
    struct stack * temp=top;

    struct tree * z=temp->loc;

    top=top->next;
    free(temp);

    return (z);
}