#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data;
    struct Node* next;
};

struct Node* Push(struct Node* top, char x)
{
    struct Node* temp1=(struct Node* )malloc(sizeof(struct Node));
    temp1->data=x;
    temp1->next=top;
    top=temp1;
    return top;
}

char Top(struct Node* top)
{
   if(top!=NULL) return top->data;
}

struct Node* Pop(struct Node* top)
{
    struct Node* temp=top;
    top=top->next;
    free(temp);
    temp=NULL;
    return top;
}

int IsEmpty(struct Node* top)
{
    if (top==NULL) { return 1;}
    else return 0;
}

int IsOperand(char x)
{
    if(x>='0' && x<='9')  return 1;
    else return 0;
}

int IsOperator(char x)
{
    if(x=='+' || x=='-' || x=='/' || x=='*' || x=='^' ) return 1;
    else return 0;
}

int Rank(char x)
{
    int rank=-1;
    switch(x)
    {
        case '+': return rank=1;
        case '-': return rank=1;
        case '*': return rank=3;
        case '/': return rank=3;
        case '^': return rank=5;
    }
    
}

int Has_Higher_Precedance(char x1, char x2)
{
    int rank1=Rank(x1);
    int rank2=Rank(x2);
    if( rank1 > rank2) return 1;
    else return 0;
}

char* Infix_To_Postfix(char* Infix, char* P, struct Node* top)
{
    int i,t=0;
    for(i=0;i< strlen(Infix);++i)       
    {
        if( Infix[i]==' ' ) continue;
        else if(Infix[i]=='(')
        {
            top=Push(top , Infix[i]);
        }else if(Infix[i]==')')
        {
            while(Top(top)!='(')
            {
                P[t++]=Top(top);
                top=Pop(top);
            }
            top=Pop(top);
        }
        else if( IsOperand(Infix[i])   )
        {
             P[t++]=Infix[i];
        }
        else if( IsOperator(Infix[i]) )
        {
            if(top==NULL) 
            {
                top=Push(top , Infix[i]);
            }else if( Top(top)!='(' && Has_Higher_Precedance( Infix[i], Top(top) ) ==1)
            {
                top=Push(top , Infix[i]);
            }else if(  Top(top)!='(' && Has_Higher_Precedance( Infix[i], Top(top) )==0)
            {
                while( !IsEmpty(top) )
                {
                    P[t++]=Top(top);
                    top=Pop(top);
                }
                top=Push(top,Infix[i]);
            }else if( Top(top)=='(')
            {
                top=Push(top , Infix[i]);
            }
        }
    }
    while( !IsEmpty(top) )
    {
        char ch= Top(top);
        P[t]=ch;
        top=Pop(top);
        t++;
    }
   return P;
    
}

int Perform_Operation(int x1, int x2, char op)
{
    switch(op)
    {
        case '+': return (x1+x2);
        case '-': return (x2-x1);
        case '*': return (x1*x2);
        case '/': return (x2/x1);
        case '^': return (x2^x1);
    }
}

int Evaluate_Postfix( struct Node* top, char* Postfix )
{
    int i, x1,x2,operation;
    char ch1,ch2, ch3;
    for(i=0;i<strlen(Postfix);++i)
    {
        if( IsOperand(Postfix[i]) )
        {
            top=Push(top , Postfix[i]);
        }else if( IsOperator(Postfix[i]) )
        {
            ch1=Top(top);
            x1=ch1-'0';
            top=Pop(top);
            ch2=Top(top);
            x2=ch2-'0';
            top=Pop(top);
            operation=Perform_Operation(x1,x2, Postfix[i]);
            ch3=operation+'0';
            top=Push(top , ch3);
        }
    }
    int Res=Top(top)-'0';
    if(top->next==NULL)
    {
        printf("The final value of the postfix evaluation is: %d\n", Res);
    }else{
        printf("The Infix expression is not balanced\n");
    }
    
}

void Delete_LinkedList(struct Node* top)
{
    struct Node* temp=NULL;
    while(top!=NULL)
    {
        temp=top;
        free(temp);
        temp=NULL;
        top=top->next;
    }
}

int main()
{
    struct Node* top=NULL;
    char *Infix=(char*)malloc(sizeof(char)*20);
    char *Postfix=(char*)malloc(sizeof(char)*20);
    printf("Enter the Infix Expression: ");
    scanf("%s", Infix);
    Postfix= Infix_To_Postfix( Infix , Postfix,top);
    printf("Postfix Expression is: %s\n", Postfix);
    Evaluate_Postfix(top, Postfix);
    
    Delete_LinkedList(top);
   
    
    return 0;
}
