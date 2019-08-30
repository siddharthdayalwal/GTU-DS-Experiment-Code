//DS Practical-2
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define P printf
#define S scanf

int stack[100],choice,n,top,x,i,pos,val;
void push(int x);
void change(int pos,int val);
void display();
void pop();
void peep();
int main()
{
    clrscr();
    top=-1;
    P("\n Enter the size of STACK[MAX=100]:");
    S("%d",&n);
    P("\n STACK OPERATIONS USING ARRAY");
    P("\n --------------------------------");
    P("\n 1.PUSH\n 2.DISPLAY\n 3.POP\n 4.PEEP\n 5.CHANGE\n 6.EXIT\n ");
    do
    {
	P("\n Enter the Choice:");
	S("%d",&choice);
	switch(choice)
	{
	    case 1:
	    {
		P(" Enter a value to be pushed:");
		S("%d",&x);
		push(x);
		break;
	    }
	    case 2:
	    {
		display();
		break;
	    }
	    case 3:
	    {
		pop();
		break;
	    }
	    case 4:
	    {
		peep();
		break;
	    }
	    case 5:
	    {
		if(top<=-1)
		{
			P("\n Stack is under flow");
		}
		else
		{
			P("\n Enter the position at which you want to change the value : ");
			S("%d",&pos);
			P("\n Enter the value to be pushed at pos-%d : ",pos);
			S("%d",&val);
			change(pos,val);
		}
		break;
	    }
	    case 6:
	    {
		P("\n EXIT POINT ");
		break;
	    }
	    default:
	    {
		P("\n Please Enter a Valid Choice(1/2/3/4)");
	    }

	}
    }
    while(choice!=6);
    return 0;
}
void push(int x)
{
	if(top>=n-1)
	{
		P("\n STACK is over flow");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}

void display()
{
    if(top>=0)
    {
	P("\n The elements in STACK \n");
	for(i=top; i>=0; i--)
	{
	    P("\n %d",stack[i]);
	}
	P("\n Press Next Choice");
    }
    else
    {
	P("\n The STACK is empty");
    }

}
void pop()
{
    if(top<=-1)
    {
	P("\n Stack is under flow");
    }
    else
    {
	P("\n The popped elements is %d",stack[top]);
	top--;
    }
}
void peep()
{
    if(top<=-1)
    {
	P("\n Stack is under flow");
    }
    else
    {
	P("\n The peeped elements is %d",stack[top]);
    }
}
void change(int pos, int val)
{
	stack[pos-1]=val;
}
