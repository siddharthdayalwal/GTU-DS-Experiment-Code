//BST
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *l_child;
   struct node *r_child;
}*root;
struct node *newnode(int x)
{
   struct node *p;
   p=malloc(sizeof(struct node));
   p->data=x;
   p->l_child=NULL;
   p->r_child=NULL;
   return p;
}
struct node* insert(struct node *root, int x)
{
   if(root==NULL)
       return newnode(x);
   else if(x>root->data)
       root->r_child = insert(root->r_child,x);
   else
       root->l_child = insert(root->l_child,x);
   return root;
}
void inorder(struct node *root)
{

   if(root!=NULL)
   {
      inorder(root->l_child);
      printf(" %d ",root->data);
      inorder(root->r_child);
   }
}
void preorder(struct node *root)
{
   if(root!=NULL)
   {
      printf(" %d ",root->data);
      preorder(root->l_child);
      preorder(root->r_child);
   }
}
void postorder(struct node *root)
{
   if(root!=NULL)
   {
      postorder(root->l_child);
      postorder(root->r_child);
      printf(" %d ",root->data);
   }
}
void main()
{
   int ch,x;
   clrscr();
   while(1)
   {
      printf("\n1.create root node\t2.insert\t3.inorder\t4.preorder\t5.postorder\t6.exit\n");
      printf("enter ur choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("\nroot value :");
		scanf("%d",&x);
		root = newnode(x);
		break;
	 case 2:printf("\nvalue to be inserted :");
		scanf("%d",&x);
		insert(root,x);
		break;
	 case 3:inorder(root);
		break;
	 case 4:preorder(root);
		break;
	 case 5:postorder(root);
		break;
	 case 6:exit (0);
      }
   }
}
