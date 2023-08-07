#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct info
{
    int id;
    char name[50];
    struct info * prev;
    struct info * next;
};

struct info * head=NULL;
struct info * tail=NULL;

int count1=0,count2=0,count3=0,count4=0,count5=0;

void display_list();
struct info * voting();
void counting();
void leaderboard();
int admin_panel();
int search(int x);

int main()
{
    int ch=0,x,z;

    for(ch=0;x!=63045;ch++)
    {
        printf("\t\t---------------Welcome to Voting Portal------------------\n");
        printf("\t\t|\tEnter                                            |\n");
        printf("\t\t|\t     1. To vote for your candidate               |\n");
        printf("\t\t|\t     2. Check Admin Page (For Officials)         |\n");
        printf("\t\t|\t     3. To check the leaderboard                 |\n");
        printf("\t\t---------------------------------------------------------\n");

        scanf("%d",&x);

        switch(x)
        {
            case 1:
            head=voting();
            break;

            case 2:
            z=admin_panel();
            break;

            case 3:
            leaderboard();
            break;
        }
    }

    return (0);
}

void display_list()
{
    printf("\t\t*\t     S.No\t   Name\t           Symbol\t     \n");
    printf("\t\t*\t     1.  \t   Ramesh\t   Pen\t      \n");
    printf("\t\t*\t     2.  \t   Suresh\t   Chair\t      \n");
    printf("\t\t*\t     3.  \t   Vikas\t   Bench\t      \n");
    printf("\t\t*\t     4.  \t   Arjun\t   Car\t      \n");
    printf("\t\t*\t     5.  \t   Amit\t           Book\t      \n");
    printf("\n");
}

struct info * voting()
{
    struct info * temp=NULL;
    temp=(struct info *)malloc(sizeof(struct info));

    if(temp==NULL)
    {
        printf("System not working \n Please contact the volunteer\n");
    }

    int a;
    char b[50];

    if(head==NULL && tail==NULL)
    {
        printf("Enter your VOTER ID\n");
        scanf("%d",&a);
        temp->id=a;

        printf("Enter your name \n");
        scanf("%s",b);
        strcpy(temp->name,b);

        temp->next=NULL;
        temp->prev=NULL;

        head=temp;
        tail=head;
        
        display_list();
        counting();

        printf("\n THANK YOU FOR VOTING \t \n\n");
    }

    else
    {
        struct info * ptr=(struct info *)malloc(sizeof(struct info));
        printf("Enter your VOTER ID\n");
        scanf("%d",&a);

        int z=search(a);
        if(z==1)
        {
        printf("SORRY ALREADY VOTED \n");
        return (0);
        }
        
        ptr->id=a;

        printf("Enter your name \n");
        scanf("%s",b);
        strcpy(ptr->name,b);

        ptr->prev=tail;
        ptr->next=NULL;
        tail->next=ptr;
        tail=ptr;
        
        display_list();
        counting();

        printf("\n THANK YOU FOR VOTING \t \n\n");
    }

    return (head);
}

void counting()
{
    int sno;

    printf("Enter the given S.No to vote for your candidate \n");
    scanf("%d",&sno);

    if(sno==1)
    {
        count1++;
    }

    if(sno==2)
    {
        count2++;
    }

    if(sno==3)
    {
        count3++;
    }

    if(sno==4)
    {
        count4++;
    }

    if(sno==5)
    {
        count5++;
    }
}

void leaderboard()
{
    if(count2<count1 && count3<count1 && count4<count1 && count5<count1)
    {
        printf("\n Ramesh is currently leading \n");
    }

    if(count1<count2 && count3<count2 && count4<count2 && count5<count2)
    {
        printf("\n Suresh is currently leading \n");
    }

    if(count1<count3 && count2<count3 && count4<count3 && count5<count3)
    {
        printf("\n Vikas is currently leading \n");
    }

    if(count1<count4 && count3<count4 && count2<count4 && count5<count4)
    {
        printf("\n Arjun is currently leading \n");
    }

    if(count1<count5 && count3<count5 && count4<count5 && count2<count5)
    {
        printf("\n Amit is currently leading \n");
    }
}

int admin_panel()
{
    int pass;
    int password=600127;

    printf("Please Enter the PASSWORD \n");
    scanf("%d",&pass);

    if(pass==password)
    {
        printf("\n Ramesh has got %d votes \n",count1);
        printf(" Suresh has got %d votes \n",count2);
        printf(" Vikas has got %d votes \n",count3);
        printf(" Arjun has got %d votes \n",count4);
        printf(" Amit has got %d votes \n",count5);

        float p;
        
        p=count1+count2+count3+count4+count5;
        
        float poll;
        poll=(p/160)*100;

        printf("\n POLLING PERCENTAGE IS  %f \n",poll);
    }

    else
    {
        printf("INCORRECT PASSWORD \n");
        return (0);
    }
}

int search(int x)
{
    struct info * front,*rear;
    front=head;
    rear=tail;

    while(front!=NULL && rear!=NULL)
    {
        if(x==front->id || x==rear->id)
        return(1);

        else
        {
            front=front->next;
            rear=rear->prev;
        }
    }
}