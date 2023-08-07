#include<stdio.h>
#include<stdlib.h>

int a[50],current=0;

void insert(int val);
void heapify(int parent);
void getmax();
void extract_max();
void increase_key();
void delete_key();
void display();

int main()
{
    int ch,val,k;
            
    for(int i=0;ch!=8;i++)
    {
        
        printf("Enter \n 1. To insert the element into heap \n 3. To get max \n 4. To extract max \n 5. To increase key \n 6. To delete \n 7. To display \n 8. To EXIT \n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            
            printf("Enter the element to be inserted \n");
            scanf("%d",&val);
            
            insert(val);
            break;
            
            case 2:
            //func
            break;
            
            case 3:
            getmax();
            break;
            
            case 4:
            extract_max();
            break;
            
            case 5:
            increase_key();
            break;
            
            case 6:
            delete_key();
            break;
            
            case 7:
            display();
            break;
        }
    }
    
    return (0);
}

void insert(int val)
{
    int parent,temp,i;
    
    if(current==0)
    {
        a[0]=val;
        current++;
    }
    
    else
    {
        a[current]=val;
        i=current;
        parent=(current-1)/2;
        
        while(a[i]>a[parent])
        {
            temp=a[i];
            a[i]=a[parent];
            a[parent]=temp;
            
            i=(i-1)/2;
            parent=(i-1)/2;
            
            if(i<=0)
            break;
        }
        
        current++;
    }
}

void getmax()
{
    printf(" MAX IS %d \n",a[0]);
}

void extract_max()
{
    a[0]=a[current-1];
    current=current-1;
    
    int i,temp1,temp2,max_child,swap;
    for(i=0;i<current;i++)
    {
        printf(" %d ",a[i]);
    }
    for(i=0;i<current;i++)
    {
        temp1=2*i+1;
        temp2=2*i+2;
        
        if(a[temp1]>a[temp2])
        {
            max_child=a[temp1];
        }
        
        else
        {
            max_child=a[temp2];
        }
        
        if(a[i]<max_child)
        {
            swap=max_child;
            max_child=a[i];
            a[i]=swap;
            
            if(a[temp1]>a[temp2])
            {
                a[temp1]=max_child;
            } 
            
            else
            {
                a[temp2]=max_child;
            }
        }
    }
    
}

void increase_key()
{
    int t,i;
    
    printf("Enter the index at which the value has to be increased \n");
    scanf("%d",&t);
    
    int x,temp;
    
    printf(" Enter the new value for %d place ",t);
    scanf("%d",&x);
    
    a[t]=x;
    
    i=t; 
    int parent=(i-1)/2;
        
    while(a[i]>a[parent])
    {
        temp=a[i];
        a[i]=a[parent];
        a[parent]=temp;
            
        i=(i-1)/2;
        parent=(i-1)/2;
            
        if(i<=0)
        break;
    }
    
}

void delete_key()
{
    int t;
    int i,temp1,temp2,max_child,swap;
    
    printf("Enter the index at which the value has to be increased \n");
    scanf("%d",&t);
    
    for(int k=t;k<current;k++)
    {
        a[k]=a[k+1];
    }
    
    current--;
    
    for(i=t;i<current;i++)
    {
        temp1=2*i+1;
        temp2=2*i+2;
        
        if(a[temp1]>a[temp2])
        {
            max_child=a[temp1];
        }
        
        else
        {
            max_child=a[temp2];
        }
        
        if(a[i]<max_child)
        {
            swap=max_child;
            max_child=a[i];
            a[i]=swap;
            
            if(a[temp1]>a[temp2])
            {
                a[temp1]=max_child;
            } 
            
            else
            {
                a[temp2]=max_child;
            }
        }
    }
}

void display()
{
    for(int j=0;j<current;j++)
    {
        printf(" %d ",a[j]);
    }
}