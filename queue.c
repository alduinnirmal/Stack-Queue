#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int rear=-1;
int front=-1;
void insert()
{
	int item=0;
	if(rear==size-1)
	{
	printf("\n!!!!!Queue is OverFlow!!!!!\n\n");
	}
	else
	{
	printf("Enter the element to be insert\n");
	scanf("%d",&item);
	if(front==-1)
	front=0;
	rear=rear+1;
	queue[rear]=item;
	}
}
void delete()
{
	if(front==-1)
	{
	printf("\n!!!!Queue is UnderFlow!!!!!\n\n");
	}
	else
	{
	printf("The deleted Element is: %d\n",queue[front]);
	front=front+1;
	}
}
void display()
{
	int i;
	if(front==-1)
	printf("!!!!!Queue is Empty!!!!!\n");
	else
	{
	for(i=front; i<=rear; i++)
	{
	printf("The Current Element is: %d\n",queue[i]);
	}
	}
}
void main()
{

	int ch;
	while(1)
	{
	printf("😎️1.INSERT\t2.DELETE\n3.DISPLAY\t4.EXIT\n");
		printf("Enter the Choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: insert();
		break;
	case 2: delete();
		break;
	case 3: display();
		break;
	case 4: exit(0);
		break;
		
	default :printf("Invalid choice");
	}

}
}
	
	
