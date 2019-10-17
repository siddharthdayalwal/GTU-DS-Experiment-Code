
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int ar[100],max,flag=0,f=1,l;
void search(int f,int x,int l)
{
   if((l-f)/2==0)
   {
      printf("\nelement not found.\n");
      return 0;
   }
   else if(x==ar[f+((l-f)/2)])
   {
      flag=1;
      printf("\nelement found.\n");
      return 0;
   }
   else if(x>ar[f+((l-f)/2)])
   {
      f=f+((l-f)/2);
      search(f,x,l);
   }
   else if(x<ar[f+((l-f)/2)])
   {
      l=l-((l-f)/2);
      search(f,x,l);
   }
}
void main()
{
   int i,x;
   clrscr();
   printf("enter the no. elements u want to enter : ");
   scanf("%d",&max);
   printf("\nfor binary search, enter the elements in ascending order.\n");\
   for(i=1;i<=max;i++)
   {
      scanf("%d",&ar[i]);
   }
   printf("enter the value u want to search : ");
   scanf("%d",&x);
   f=1;
   l=max;
   search(f,x,l);
   getch();
}
