//DS Practical-1
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define P printf
#define S scanf
int n;
void INSERT(int a[], int pos, int val);
void DELETE(int a[], int pos);
void SEARCH(int a[], int val);
void DISPLAY(int a[]);
void main()
{
	clrscr();
	int *a,c,i,pos,val;
	P("\n Enter the no. of value you want to get : ");
	S("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	P("\n Enter %d values : \n",n);
	for(i=0;i<n;i++)
	{
		P(" ");
		S("%d",&a[i]);
	}
	do
	{
	start:

	P("\n Choose any code of operation from below listed : ");
	P("\n Insert a value :1 ");
	P("\n Delete a value :2 ");
	P("\n Search a value :3 ");
	P("\n Exit now       :4 ");
	P("\n \n Enter the code : ");
	S("%d",&c);
	switch(c)
	{
		case 1:
		{
			again:
			P("\n Enter the position at which you want to insert the value : ");
			S("%d",&pos);
			if(pos>n+1)
			{
				P("\n Out of range, enter the position again \n");
				goto again;
			}
			P("\n Enter the value you want to insert at position %d : ",pos);
			S("%d",&val);
			INSERT(a,pos,val);
			DISPLAY(a);
			break;
		}
		case 2:
		{
			P("\n Enter the position at which you want to delete the value : ");
			S("%d",&pos);
			DELETE(a,pos);
			DISPLAY(a);
			break;
		}
		case 3:
		{
			P("\n Enter the value you want to search : ");
			S("%d",&val);
			SEARCH(a,val);
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			P("\n Wrong code Entered, Enter the code again \n");
			goto start;
		}
	}
	}while(c!=4);
	getch();
}
void INSERT(int *a, int pos, int val)
{
	int i;
	n=n+1;
	for(i=n;i>=pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos-1]=val;
}
void DELETE(int *a, int pos)
{
	int i;
	for(i=pos-1;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n=n-1;
}
void SEARCH(int *a, int val)
{
	int i,z=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==val)
		{
			P("\n Value %d is found at position %d \n",val,i+1);
			z=1;
		}
	}
	if(z==0)
	{
		P("\n Value %d not found \n", val);
	}
}
void DISPLAY(int *a)
{
	int i;
	for(i=0;i<n;i++)
	{
		P(" %d\t",a[i]);
	}
	P("\n");
}


