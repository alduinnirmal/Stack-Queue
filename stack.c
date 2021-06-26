#include<stdio.h>
#include<stdlib.h>
int stack[100],n,p,top=-1,ch,i;
void push()
{
	if(top>=n-1)
	{
	printf("The Stack is full!!!\n");
	}
	else
	{
	printf("Enter the element to be pushed\n");
	scanf("%d",&p);
	top++;
	stack[top]=p;
	printf("The pushed element=%d\n",p);
	}
}
void pop()
{
	if(top<=-1)
	{
	printf("The stack is Empty!!!\n");
	}
	else
	{
	printf("The poped element=%d\n",stack[top]);
	top--;
	}
}
void display()
{
	if(top>=0)
	{
		for(i=top; i>=0; i--)
		printf("The current element in stack=%d\n",stack[i]);
	}
	else
		printf("The stack is empty\n");
	
}
void main()
{
	printf("Enter the size of the Stack\n");
	scanf("%d",&n);
	printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
	do
	{
	printf("Enter the choice\n",ch);
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: push();
			break;
		case 2:pop();
			break;
		case 3:display();
			break;
		case 4:exit(0);
			break;
		default : printf("Invalid Choice\n");
	}
	}
	while(ch!=4);
	
}

