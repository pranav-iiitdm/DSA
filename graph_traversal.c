#include<stdio.h>
#include<stdlib.h>

struct graph
{
    int v;
    int e;
    int ** adjmatrix;
};

struct stack
{
    int data;
    struct stack * next;
};

struct stack * top=NULL;

struct visited
{
    int data;
    struct visited * next;
};

struct visited * head=NULL;
struct visited * end=NULL;

struct queue
{
    int data;
    struct queue * next;
};

struct queue * front=NULL;
struct queue * rear=NULL;

struct visited1
{
    int data;
    struct visited1 * next;
};

struct visited1 * head1=NULL;
struct visited1 * end1=NULL;

void push(int z);
int pop();

void enqueue(int c);
int dequeue();

int search_visited(int a);
int search_visited1(int a);

struct graph * adjmat(int x);
void display(struct graph * graph,int x);
void dfs(struct graph * graph,int x);
void display_dfs();
void bfs(struct graph * graph,int x);
void display_bfs();

int main()
{
    int x,ch;
    
    printf("Enter no.of vertices \n");
    scanf("%d",&x);
    
    struct graph * graph=adjmat(x);
    display(graph,x);
    
    printf(" Enter \n 1. For DFS traversal \n 2. For BFS traversal \n");
    scanf("%d",&ch);
    
    if(ch==1)
    {
        dfs(graph,x);
        display_dfs();
    }
    
    if(ch==2)
    {
        bfs(graph,x);
        display_bfs();
    }
    
    return (0);
}



struct graph * adjmat(int x)
{
    struct graph * gph=(struct graph *)malloc(sizeof(struct graph));
    int max_edge,start,end;
    
    max_edge=x*(x-1);
    
    gph->v=x;
    gph->e=max_edge;
    
    gph->adjmatrix=(int **)malloc(x*sizeof(int *));
    
    for(int k=0;k<x;k++)
    {
        gph->adjmatrix[k]=(int *)malloc(x*sizeof(int));
    }
    
    for(int i=1;i<=max_edge;i++)
    {
        printf("Enter the start and end for the %d edge [-1 -1 (to exit)] \n",i);
        scanf("%d%d",&start,&end);
        
        if(start==-1 && end==-1)
        {
            break;
        }
        
        else
        {
            gph->adjmatrix[start][end]=1;
        }
    }
    
    return (gph);
}

void display(struct graph * graph,int x)
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            printf(" %d ",graph->adjmatrix[i][j]);
        }
        printf("\n");
    }
}



int search_visited(int a)
{
    struct visited * temp=head;
    
    while(temp!=NULL)
    {
        if(temp->data==a)
        return (1);
        
        else
        temp=temp->next;
    }
    
    return (0);
}

int search_visited1(int a)
{
    struct visited1 * temp1=head1;
    
    while(temp1!=NULL)
    {
        if(temp1->data==a)
        return (1);
        
        else
        temp1=temp1->next;
    }
    
    return (0);
}



void dfs(struct graph * graph,int x)
{
    int index,b,vis;
    
    printf(" Enter the value of entry point for the traversal \n");
    scanf("%d",&index);
    
    push(index);
    
    while(top!=NULL)
    {
        struct visited * ptr=(struct visited *)malloc(sizeof(struct visited));
        
        vis=pop();
        b=search_visited(vis);
        
        if(b==0)
        {
            if(head==NULL && end==NULL)
            {
                ptr->data=vis;
                //printf(" %d ",vis);
                ptr->next=NULL;
                head=ptr;
                end=ptr;
            }
            
            else
            {
                ptr->data=vis;
                //printf(" %d ",ptr->data);
                ptr->next=NULL;
                end->next=ptr;
                end=ptr;
            }
        }
        
        
        for(int i=0;i<x;i++)
        {
            if(graph->adjmatrix[vis][i]==1)
            {
                if(search_visited(i)==0)
                push(i);
            }
        }
    }
}

void display_dfs()
{
    while(head!=NULL)
    {
        printf(" %d ",head->data);
        head=head->next;
    }
}



void bfs(struct graph * graph,int x)
{
    int index,b,vis;
    
    printf(" Enter the value of entry point for the traversal \n");
    scanf("%d",&index);
    
    enqueue(index);
    
    while(front!=NULL && rear!=NULL)
    {
        struct visited1 * ptr1=(struct visited1 *)malloc(sizeof(struct visited1));
        
        vis=dequeue();
        b=search_visited1(vis);
        
        if(b==0)
        {
            if(head1==NULL && end1==NULL)
            {
                ptr1->data=vis;
                ptr1->next=NULL;
                head1=ptr1;
                end1=ptr1;
            }
            
            else
            {
                ptr1->data=vis;
                ptr1->next=NULL;
                end1->next=ptr1;
                end1=ptr1;
            }
        }
        
        
        for(int i=0;i<x;i++)
        {
            if(graph->adjmatrix[vis][i]==1)
            {
                if(search_visited1(i)==0)
                enqueue(i);
            }
        }
    }
}

void display_bfs()
{
    while(head1!=NULL)
    {
        printf(" %d ",head1->data);
        head1=head1->next;
    }
}



void push(int z)
{
    struct stack * ptr=(struct stack *)malloc(sizeof(struct stack));
    
    if(top==NULL)
    {
        ptr->data=z;
        ptr->next=NULL;
        
        top=ptr;
    }
    
    else
    {
        ptr->data=z;
        ptr->next=top;
        top->next=NULL;
        top=ptr;
    }
}

int pop()
{
    struct stack * temp=NULL;
    
    temp=top;
    
    int z=top->data;
    
    top=top->next;
    
    free(temp);
    return (z);
}



void enqueue(int c)
{
    struct queue * ptr=(struct queue *)malloc(sizeof(struct queue));
    
    if(front==NULL && rear==NULL)
    {
        ptr->data=c;
        ptr->next=NULL;
        front=ptr;
        rear=ptr;
    }
            
    else
    {
        ptr->data=c;
        ptr->next=NULL;
        rear->next=ptr;
        rear=ptr;
    }
}

int dequeue()
{
    struct queue * temp=NULL;
    
    temp=front;
    
    int z=front->data;
    
    front=front->next;
    
    free(temp);
    return (z);
}