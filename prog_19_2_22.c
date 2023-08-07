#include<stdio.h>

void swap(int a,int b);
void swap1(int *pa,int *pb);

int main()
{
  int a=5,b=10;
  
  printf("Before swap a=%d  b=%d  \n",a,b);
  swap(a,b);

  printf("After swap a=%d  b=%d  \n",a,b);

  printf("Before swap a=%d  b=%d  \n",a,b);
  swap1(&a,&b);
  printf("After swap a=%d  b=%d  \n",a,b);

  return (0);
}

void swap(int a,int b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;

}

void swap1(int *pa,int *pb)
{
  int temp;
  temp=*pa;
  *pa=*pb;
  *pb=temp;

}
