#include<stdio.h>
#include<stdlib.h>

struct polynomial 
{
	int coeff;
	int exp;
	struct polynomial * next;
};

struct polynomial * head;

void createlist(int m);
void displaylist();

int main()
{
	int n,m,i;
	
	printf("Enter the number of polynomials \n");
	scanf("%d",&n);
	
	for(i=0;i<n;++i)
	{
		printf("Enter the number of coefficients of the polynomial %d \n",(i+1));
		scanf("%d",&m);
	
		printf("Enter the data for polynomial #%d \n",(i+1));
		createlist(m);
		displaylist();
	}


	return (0);
}

void createlist(int m)
{
	struct polynomial *ptr,*temp;
	int c,e,i;
	
	head=(struct polynomial *)malloc(sizeof(struct polynomial));
	
	if(head==NULL)
	printf("No memory is allocated \n");
	
	
	else
	{

		printf("Enter the coefficient \n");
		scanf("%d",&c);
		printf("Enter the exponent value \n");
		scanf("%d",&e);
	
		head->coeff=c;
		head->exp=e;	
		head->next=NULL;
		temp=head;
	}

	for(i=2;i<=m;++i)
	{
		ptr=(struct polynomial *)malloc(sizeof(struct polynomial));
		
		if(ptr==NULL)
		printf("No memory is allocated \n");
		
		else
		{
			//printf("Enter the data for polynomial #%d \n",i);
			printf("Enter the coefficient \n");
			scanf("%d",&c);
			printf("Enter the exponent value \n");
			scanf("%d",&e);
			
			ptr->coeff=c;
			ptr->exp=e;
			ptr->next=NULL;
			
			temp->next=ptr;
			temp=temp->next;
		}
	}
}

void displaylist()
{
	struct polynomial *temp;

	if(head==NULL)
	printf("No memory allocated \n");

	else
	{
		temp=head;

		while(temp!=NULL)
		{
			  printf(" %d.x^%d ",temp->coeff,temp->exp);
			  //printf(" x^%d ",temp->exp);
			  temp=temp->next;
		}
	}
}

