//DS Practical-3
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#define P printf
#define S scanf
void pop_to_post();
void dispstack();
void disppostfix();
void push_to_post(char);
void push_to_stack(char);
int prior(char);
int val1,val2=-1;
char postfix[100];
char stack[100];
char infix[100];
int i=0,len,top=0,pot=1,flag=0,j,k,l;
void main()
{

	clrscr();
	P("\nEnter the INFIX with extra ')' at the end :\n \n");
	gets(infix);
	len=strlen(infix);
	P("\nINPUT\t\t\t STACK\t\t\t POSTFIX\n");
	P("\n\t\t\t ");
	gets(stack);
	do
	{
		if(infix[i]>='A' && infix[i]<='Z')
		{
			flag=1;
			push_to_post(infix[i]);
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
		{
			push_to_stack(infix[i]);

		}
		else if(infix[i]==')')
		{
			flag=2;
			pop_to_post();
		}
		else
		{
			flag=1;
			push_to_stack(infix[i]);
		}
		P("\n%c\t\t\t ",infix[i]);
		if(flag==1)
		{
			dispstack();
			P("\t\t\t ");
			disppostfix();
		}
		if(flag==2)
		{
			k=pot;
			k--;
			if(k>=0)
			{
				for(j=0; j<=k; j++)
				{
					P("%c",stack[j]);
				}
			}

			P("\t\t\t ");
			disppostfix();

		}
		i++;
		getch();
	}
	while(infix[i]!='\0');
	getch();
}
void push_to_post(char infix)
{
	postfix[top]=infix;
	top++;
}
void push_to_stack(char infix)
{
	stack[pot]=infix;
	pot++;
}
void pop_to_post()
{
	{
		pot--;
		do
		{
			push_to_post(stack[pot]);
			pot--;
		}
		while(stack[pot]!='(');
	}
}
void dispstack()
{
    if(pot>=0)
    {
	for(j=0; j<=pot-1; j++)
	{
	    P("%c",stack[j]);
	}
    }
}
void disppostfix()
{
    if(top>=0)
    {
	for(j=0; j<=top; j++)
	{
	    P("%c",postfix[j]);
	}
    }
}
int prior(char infix)
{
	int r=0;
	char op[]={'+','-','*','/','^'};
	char pr[]={0,0,1,1,2};
	int ret;
	do
	{
		if(infix==op[r])
		{
			ret=pr[r];
			break;
		}
		r++;
	}
	while(r<=4);
	return ret;
}

