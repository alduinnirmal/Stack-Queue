#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char x)
{
	top=top+1;
	stack[top]=x;
}
char pop()
{
	char temp;
	if(top==-1)
	return -1;
	else
	{
		temp=stack[top];
		top=top-1;
		return temp;
	}
}
int priority(char x)
{
	if(x=='+' || x=='-')
		return 1;
	if(x=='*' || x=='/')
		return 2;
	if(x=='^')
		return 3;
	if(x=='(')
		return 0;
}
int opertor(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
		return 1;
	else
		return 0;
}
void main()
{
	char exp[100],result[100];
	char x,temp;
	int i=0,j=0;
	printf("Enter the Expression:\n");
	scanf("%s",exp);
	
	while(exp[i]!='\0')
	{
		x=exp[i];
		if(x=='(')
		push(x);
		else if(opertor(x))
		{
			temp=pop();
		while(priority(temp)>=priority(x))
		{
			result[j]=temp;
			j++;
			temp=pop();
		}
		push(temp);
		pop(temp);
		}
		else if(x==')')
		{
			temp=pop();
		while(temp!='(')
		{
			result[j]=temp;
			j++;
			temp=pop();
		}
		}
		else
		{
			result[j]=x;
			j++;
		}
		i++;
	}
	while(top>=0)
	{
	exp[++j]=pop(stack);
	}
	printf("Final Expression=%s\n",result);
}
			
			
		
	
	
