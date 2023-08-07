#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
	char data;
	struct node * next;
};

struct node * top=NULL;

void push(char ele);
char pop();
char * conversion(char * exp,char * p);
void evaluation(char * res);

int main()
{
	char * exp;
	exp=(char *)malloc(sizeof(char)*50);
	
	char * res;
	res=(char *)malloc(sizeof(char)*50);
	
	printf("Enter the infix expression \n");
	fgets(exp,50,stdin);
	
	int n=strlen(exp);
	//printf(" %d \n",n);
	exp[n-1]=')';
	push('(');
	
	//printf(" %s \n ",exp);
	
	res=conversion(exp,res);
	//printf(" %c ",top->data);
	printf(" %s \n",res);
	
	//printf(" %d \n",top->data);
	
	evaluation(res);
	
	return (0);
}

void push(char ele)
{
	struct node * temp;
	temp=(struct node*)malloc(sizeof(struct node));
	
	if(top==NULL)
	{	
		temp->data=ele;
		temp->next=NULL;
	}
	
	else
	{
		temp->data=ele;
		temp->next=top;
	}
	
	top=temp;
}

char pop()
{
	struct node * temp;
	
	temp=top;
	
	char item;
	item=top->data;
	
	top=top->next;
	free(temp);
	
	return (item);
}

char * conversion(char * exp,char * p)
{
	//push('(');
	char temp;
	int i,k;
	
	int t=0;
	
	for(i=0;i<strlen(exp);++i)
	{
		if(exp[i]>=48 && exp[i]<=57)
		{
			p[t]=exp[i];
			t++;
		}
		
		if(exp[i]==top->data)
		{
			p[t]=exp[i];
			t++;
		}
	
		if(exp[i]=='(')
		{
			push('(');
		}
		
		if((exp[i]=='+' || exp[i]=='-' || exp[i]=='/' || exp[i]=='*' || exp[i]=='^') && top->data=='(')
		{
			push(exp[i]);
		}
		
		if(exp[i]=='-' && top->data=='+')
		{
				p[t]=pop();
				push(exp[i]);
				t++;
		}
		
		if(exp[i]=='+' && top->data=='-')
		{
				p[t]=pop();
				push(exp[i]);
				t++;
		}
		
		if((exp[i]=='/') && (top->data=='*'))
		{
				p[t]=pop();
				push(exp[i]);
				t++;
		}
		
		if(exp[i]=='*' && top->data=='/')
		{
				p[t]=pop();
				push(exp[i]);
				t++;
		}
		
		if(exp[i]==')')
		{
			while(top->data!='(')
			{
				p[t]=pop();
				t++;
			}
			
			temp=pop();
		}
		
		if((exp[i]=='+' || exp[i]=='-') && (top->data=='^' || top->data=='/' || top->data=='*'))
		{
			while(top->data!='(')
			{
				p[t]=pop();
				//push(exp[i]);
				t++;
			}
			push(exp[i]);
			
			if(exp[i]=='-' && top->data=='+')
			{
				p[t]=pop();
				push(exp[i]);
				t++;
			}
		
			if(exp[i]=='+' && top->data=='-')
			{
				p[t]=pop();
				push(exp[i]);
				t++;
			}
		}
		
		if((exp[i]=='*') && top->data=='^')
		{
			while(top->data!='(')
			{
				p[t]=pop();
				//push(exp[i]);
				t++;
			}
			push(exp[i]);
		}
		
		if((exp[i]=='/') && top->data=='^')
		{
			while(top->data!='(')
			{
				p[t]=pop();
				//push(exp[i]);
				t++;
			}
			push(exp[i]);
		}
		
		if(exp[i]=='^' && (top->data=='+' || top->data=='-' || top->data=='*' || top->data=='/'))
		{
			push(exp[i]);
		}
		
		if((exp[i]=='*' || exp[i]=='/') && (top->data=='+' || top->data=='-'))
		{
			push(exp[i]);
		}
	}
	
	return p;

}

void evaluation(char * res)
{
	int x1,x2,ans,i;
	char temp,ch1,ch2;
	
	for(i=0;i<strlen(res);i++)
	{
		if(res[i]>=48 && res[i]<=57)
		{
			push(res[i]);
		}
		
		if(res[i]=='+')
		{
			ch1=pop();
			x1=ch1-'0';
			ch2=pop();
			x2=ch2-'0';
			ans=x1 + x2;
			temp=ans+'0';
			//printf(" %d \n",temp);
			push(temp);
		}
		
		if(res[i]=='-')
		{
			ch1=pop();
			x1=ch1-'0';
			ch2=pop();
			x2=ch2-'0';
			ans=x2 - x1;
			temp=ans+'0';
			push(temp);
		}
		
		if(res[i]=='*')
		{
			ch1=pop();
			x1=ch1-'0';
			ch2=pop();
			x2=ch2-'0';
			ans=x1 * x2;
			temp=ans+'0';
			push(temp);
		}
		
		if(res[i]=='/')
		{
			ch1=pop();
			x1=ch1-'0';
			ch2=pop();
			x2=ch2-'0';
			ans=x2/x1;
			temp=ans+'0';
			push(temp);
		}
		
		if(res[i]=='^')
		{
			ch1=pop();
			x1=ch1-'0';
			ch2=pop();
			x2=ch2-'0';
			ans=pow(x2,x1);
			temp=ans+'0';
			push(temp);
		}
	}
		
	long int val=pop()-'0';
	
	printf("The final value of postfix expression is %ld \n",val);

}
