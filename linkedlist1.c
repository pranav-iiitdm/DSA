#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int rollno;
char name[50];
char courseid[10];
int marks;
struct node * next;
};

void createlist(int n);
void displaylist(int n);

struct node * head;

int main()
{
	int n;

	printf("Enter the number of students \n");
	scanf("%d",&n);

	createlist(n);
	displaylist(n);

	return (0);
}

void createlist(int n)
{
	int rno;
	char s[50];
	char c[10];
	int m,i;	
	
	struct node * ptr,*temp;
	
	head=(struct node *)malloc(sizeof(struct node));
	
	if(head==NULL)
	printf("No memory is allocated \n");

	else
	{
		printf("Enter the data for the node 1 \n");
		printf("Student roll number :");
		scanf("%d",&rno);
		
		printf("Student name :");
		scanf("%s",s);
		
		for(i=0;i<4;++i)
		{
			printf("Enter course id no.%d \n",(i+1));
			scanf("%s",c);
			printf("Enter marks for course no.%d \n",(i+1));
			scanf("%d",m);	
		}
		
		head->rollno=rno;
		strcpy(head->name,s);
		strcpy(head->courseid,c);
		head->marks=m;
		head->next=NULL;
		
		temp=head;
	
	}
	
	for(i=2;i<=n;++i)
	{
		printf("Enter the data for the node %d \n",i);
	
		ptr=(struct node*)malloc(sizeof(struct node));

		if(ptr==NULL)
		{
			printf("No memory is allocated \n");
			break;
		}
		else
		{
			printf("Student roll number :");
			scanf("%d",&rno);
		
			printf("Student name :");
			scanf("%s",s);
		
			for(i=0;i<4;++i)
			{
				printf("Enter course id no.%d \n",(i+1));
				scanf("%s",c);
				printf("Enter marks for course no.%d \n",(i+1));
				scanf("%d",m);	
			}
		
			temp->next=ptr;
			temp=temp->next;

		}

	}

}

void displaylist(int n)
{
	int i;
	struct node *temp;

	if(head==NULL)
	printf("No memory allocated \n");

	else
	{
		temp=head;

		while(temp!=NULL)
		{
			printf(" %d ",temp->rollno);
			 printf(" %s ",temp->name);
			for(i=0;i<4;++i)
			{
			  printf(" %s ",temp->courseid);
			  printf(" %d ",temp->marks);
			 
			} 
			 temp=temp->next;
		}
	}

}
