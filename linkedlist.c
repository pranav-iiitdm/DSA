#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node * next;
};

struct node * head;

void createlist(int n);
void displaylist();
void middle(struct node*head);
void middleonepass(struct node *head);
void reverselist(struct node *head);
void insert();
void delete();

int main()
{

	int n;
	printf("Enter the number of elements to be in the linked list \n");
	scanf("%d",&n);

	createlist(n);
	displaylist();
	printf("\n");
	//middle(head);
	//middleonepass(head);
	//reverselist(head);
	//insert();
	//displaylist();
	//delete();
	//displaylist();
	//delete();
	//displaylist();

	return (0);
}

void createlist(int n)
{

	int x,i;
	struct node * ptr,*temp;

	head=(struct node*)malloc(sizeof(struct node));

	if(head==NULL)
	printf("No memory is allocated \n");

	else
	{
		//creating the first node
		printf("Enter the data for 1st node \n");
		scanf("%d",&x);

		head->data=x;
		head->next=NULL;
		temp=head;

	}

	for(i=2;i<=n;++i)
	{
		ptr=(struct node*)malloc(sizeof(struct node));

		if(ptr==NULL)
		{
			printf("No memory is allocated \n");
			break;
		}
		else
		{
			printf("Enter the element for %d node \n",i);
			scanf("%d",&x);

			ptr->data=x;
			ptr->next=NULL;

			temp->next=ptr;
			temp=temp->next;

		}

	}
	
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;

}

void displaylist()
{
	struct node *temp;

	if(head==NULL)
	printf("No memory allocated \n");

	else
	{
		temp=head;

		while(temp->next!=head)
		{
			  printf(" %d ",temp->data);
			  temp=temp->next;
		}
		printf(" %d ",temp->data);
		//temp->next=head;
	}
}

void middle(struct node*head)
{

	struct node *temp;
	int count=0,i;

	if(head==NULL)
	printf("No memory allocated \n");

	else
	{
		temp=head;

		while(temp!=NULL)
		{
			temp=temp->next;
			count++;
		}

		temp=head;

		if(count%2!=0)
		{
			for(i=1;i<(count/2)+1;++i)
			{
				temp=temp->next;

			}
			printf("Middle element is %d \n",temp->data);
		}

		else
		{
			for(i=1;i<(count/2);++i)
			{
				temp=temp->next;

			}
			printf("Middle element is %d \n",temp->data);
		}

	}

}

void middleonepass(struct node *head)
{
	struct node * temp;
	struct node * slowptr=head;
	struct node * fastptr=head;
	temp=head;
	
	while(fastptr!=NULL && fastptr->next!=NULL)
	{
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
	}
	
	printf("Middle element is %d \n",slowptr->data);

}

void reverselist(struct node *head)
{
	struct node * prev,*current,*nextnode;
	
	prev=NULL;
	current=nextnode=head;
	
	
	while(nextnode!=NULL)
	{
		nextnode=nextnode->next;
		current->next=prev;
		prev=current;
		current=nextnode;
	}
	
	head=prev;
	
	struct node *temp;
	temp=head;
	
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}
}

void insert()
{
	int p,x,i,count=0;
	struct node *temp;

	printf("Enter the position after which the new node has to be inserted \n");
	scanf("%d",&p);
	
	printf("Enter the data for new node \n");
	scanf("%d",&x);
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	else
	{
		temp=head;
		
		for(i=1;i<p;++i)
		{
			temp=temp->next;
		}
		
		printf(" %d \n",temp->data);
		
		struct node *new;
		new=(struct node *)malloc(sizeof(struct node));
		
		if(new==NULL)
		printf("No memory is allocated \n");
		
		else
		{
			new->data=x;
		
			new->next=temp->next;
			temp->next=new;
		}	
	}
}

void delete()
{
	int p,i,count=0;
	struct node *temp;
	struct node *ptr;

	printf("Enter the position of node that has to be deleted \n");
	scanf("%d",&p);
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	else
	{
		temp=head;
		
		while(temp!=NULL)
		{
			count=count+1;
			temp=temp->next;
		}
		//printf("length = %d \n",count);
		
		temp=head;
		ptr=head;
		
		if(p==1)
		{
			temp=head;
			head=temp->next;
			free(temp);
		}
		
		else
		{
			for(i=1;i<p-1;++i)
			{
				ptr=ptr->next;
			}		
			
			temp=ptr->next;
			ptr->next=temp->next;
			temp->next=ptr;
			free(temp);
		}	
	}	
}
