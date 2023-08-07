#include<stdio.h>
#include<stdlib.h>

struct twl{

int data;
struct twl * forw;
struct twl * back;

};

struct twl * head;

void createlist(int n);
void displaylist();
void insert();
void delete();
void reverse();
void search();

int main()
{
	int n;
	
	printf("Enter the number of elements in the list \n");
	scanf("%d",&n);

	createlist(n);
	displaylist();
	insert();
	displaylist();
	printf("\n");
	//reverse();
	//delete();
	//displaylist();
	//search();

	return (0);
}

void createlist(int n)
{
	struct twl *temp,*ptr;
	int x,i;
	
	head=(struct twl *)malloc(sizeof(struct twl));
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	else
	{
		printf("Enter the data for node 1 \n");
		scanf("%d",&x);
		
		head->data=x;
		head->forw=NULL;
		head->back=NULL;
		
		temp=head;
	}
	
	for(i=2;i<=n;++i)
	{
		ptr=(struct twl *)malloc(sizeof(struct twl));
		
		if(ptr==NULL)
		printf("No memory is allocated \n");
		
		else
		{
			printf("Enter the data for node %d \n",i);
			scanf("%d",&x);
			
			ptr->data=x;
			ptr->forw=NULL;
			ptr->back=temp;
			
			temp->forw=ptr;
			temp=temp->forw;
		}
	}
}	

void displaylist()
{
	struct twl *temp;
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	else
	{
		temp=head;
		
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->forw;
		}	
		//printf(" %d ",temp->forw);
	}

}

void insert()
{
	int p,count=0,i,x;
	struct twl *temp;

	printf("Enter the position of the new node after insertion \n");
	scanf("%d",&p);
	
	printf("Enter the data for new node \n");
	scanf("%d",&x);
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	else
	{
		temp=head;
		
		while(temp!=NULL)
		{
			count=count+1;
			temp=temp->forw;
		}
			//printf("length = %d \n",count);
					
		if(p==1)
		{
			struct twl *new;
			
			new=(struct twl *)malloc(sizeof(struct twl));
			
			if(new==NULL)
			printf("No memory is allocated \n");
			
			else
			{		
				new->data=x;
				new->back=NULL;

				new->forw=head;
				head->back=new;
				
				head=new;
			}
		}
			
		else if(p>=count+1)
		{
			struct twl *new;
			
			new=(struct twl *)malloc(sizeof(struct twl));
			
			if(new==NULL)
			printf("No memory is allocated \n");
			
			else
			{	
				temp=head;
				while(temp->forw!=NULL)
				{
					temp=temp->forw;
				}
						
				new->data=x;
				new->back=temp;
				new->forw=NULL;
				
				temp->forw=new;		
			}
		}
			
		else
		{
			temp=head;
			i=1;
			while(i<p-1)
			{
				temp=temp->forw;
				i++;
			}
			
			struct twl *new;
		
			new=(struct twl *)malloc(sizeof(struct twl));
			
			if(new==NULL)
			printf("No memory is allocated \n");
			
			else
			{		
				new->data=x;
				
				(temp->forw)->back=new;
				new->forw=temp->forw;
				
				temp->forw=new;
				new->back=temp;
			}
		}
	} 
}

void delete()
{
	int p,count=0,i;
	struct twl *temp;
	struct twl* ptr;
	
	printf("Enter the position of node to be deleted \n");
	scanf("%d",&p);
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	else
	{
		temp=head;
		
		while(temp!=NULL)
		{
			count=count+1;
			temp=temp->forw;
		}
		temp=head;
		if(p==1)
		{
			
			(temp->forw)->back=NULL;
			head=temp->forw;
			free(temp);	
		}
		
		else if(p==count)
		{
			temp=head;
			while(temp->forw!=NULL)
			{
				temp=temp->forw;
			}
			
			temp->back->forw=NULL;
			free(temp);
		}
		
		else
		{
			temp=head;
			
			i=1;
			while(i<p)
			{
				temp=temp->forw;
				i++;
			}
			
			temp->back->forw=temp->forw;
			temp->forw->back=temp->back;
			//free(temp);
		}
	}
}

void reverse()
{
	struct twl *temp;
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	else
	{
		temp=head;
		
		while((temp->forw)!=NULL)
		{
			//printf(" %d ",temp->data);
			temp=temp->forw;
		}	
		//printf(" %d ",temp->data);
		
	}
	
	struct twl *ptr;
		ptr=(struct twl *)malloc(sizeof(struct twl));
		
		if(ptr=NULL)
		printf("No memory is allocated /n");
		
		else
		{
			ptr=temp;
			
			while(ptr!=NULL)
			{
				printf(" %d ",ptr->data);
				ptr=ptr->back;
			}
		}
}

void search()
{
	int ITEM,count=0;
	struct twl *temp;
	
	printf("Enter the item to be searched \n");
	scanf("%d",&ITEM);
	
	temp=head;
	
	while(temp->forw!=NULL)
	{
		if(temp->data==ITEM)
		{
			printf("Search successful \n");
			break;
		}	
		
		else
		{
			temp=temp->forw;
			count++;
		}	
	}	
	
	if(count>1)
	printf("Search unsucessful \n");

}
