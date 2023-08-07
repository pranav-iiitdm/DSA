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
  struct tree * address;
  struct stack * next;
};

struct stack * top=NULL;

struct tree * create();
//struct stack * create_node(struct stack * temp,struct tree * root);
void push(struct tree * temp1);
struct tree * pop();
int stackIsempty();

void preorder();
void inorder(struct tree * root);
void postorder();

int main()
{
    root=create();
    //printf(" %d ",root->data);
    preorder();
    inorder(root);
    postorder();
    return (0);
}

struct tree * create()
{
    int x;
    struct tree * newnode=(struct tree *)malloc(sizeof(struct tree));
    
    printf("Enter the data for newnode \n");
    scanf("%d",&x);
    
    if(x==0)
    return (0);
    
    newnode->data=x;
    
    printf("Insert the left branch for %d \n",x);
    newnode->left=create();
    
    printf("Insert the right branch for %d \n",x);
    newnode->right=create();
    
    return (newnode);
}

/*struct stack * create_node(struct stack * temp,struct tree * root)
{
    temp=(struct stack *)malloc(sizeof(struct stack));
    
    if(top==NULL)
    {
        top->address=root;
        top->next=NULL;
        temp=top;
    }
    
    else
    {
        temp->address=root;
        temp->next=top;
        top=temp;
    }
    
    return (top);
}*/

void push(struct tree * temp1)
{
    struct stack * temp=(struct stack *)malloc(sizeof(struct stack));
    
    if(top==NULL)
    {
        temp->address=temp1;
        temp->next=NULL;
        top=temp;
    }
    
    else
    {
        temp->address=temp1;
        temp->next=top;
        top=temp;
    }
}

struct tree * pop()
{
    struct stack * temp2;
    
    temp2=top;
    
    struct tree * temp=temp2->address;
    
    top=top->next;
    
    free(temp2);
    
    return (temp);
}

int stackIsempty()
{
    if(top==NULL)
    return (1);

    else
    return (0);
}

void preorder()
{
    struct tree * temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            printf(" %d ",temp->data);
            
            push(temp);
            
            temp=temp->left;
        }

        if(stackIsempty()==1)
        break;

        temp=pop();
        temp=temp->right;
    }
}

void inorder(struct tree * root)
{
    //printf("123\n");
    struct tree * temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            push(temp);
            
            temp=temp->left;
        }
        
        if(stackIsempty()==1)
        break;
        
        //printf(" %d ",temp->data);
        temp=pop();
        printf(" %d ",temp->data);
        temp=temp->right;
        
    }
}

void postorder()
{
    printf("123\n");
    struct tree * temp=root;

    while(1)
    {
        while(temp!=NULL)
        {
            if(temp->right!=NULL)
            push(temp->right);

            push(temp);
        }
        printf("123\n");
        if(stackIsempty()==1)
        break;

        temp=pop();

        if(temp->right && top->address==temp->right)
        {
            pop();
            push(temp);
            temp=temp->right;
        }

        else
        {
            printf(" %d ",temp->data);
            temp=NULL;
        }
    }
}