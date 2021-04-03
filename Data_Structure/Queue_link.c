#include<stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
}; struct node *front=NULL;
	struct node *rear=NULL;
void insert(int num)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element:\n");
	scanf("%d",&num);
	newnode->data = num;
	newnode->link = 0;
	if(rear == NULL && front == NULL)
		front=rear=newnode;
	else
	{
		rear->link = newnode;
		rear = newnode;
	}
}
void delete()
{
	struct node *temp;
	temp = front;
	if(front == NULL && rear == NULL)
		printf("Queue is Empty!!!\n");
	else
	{
		printf("Deleted element = %d\n", temp->data);
		front = front->link;
	}
}
void display()
{
	struct node *temp;
	temp = front;
	if(front == NULL && rear == NULL)
		printf("Queue is Empty!!!\n");
	else
	{
		while(temp!=NULL)
		{
		printf("%d\n",temp->data );
		temp=temp->link;
		}
	}
}
void main()
{	
	int ch,num;
	do{
	printf("Enter the choice _>\n1.INSERT\t2.DELETE\n3.DISPLAY\t4.EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert(num);
			break;
		case 2:delete();
			break;
		case 3:display();
			break;
		case 4:exit(0);
			break;
		default:printf("Invalid choice\n");
			break;
	}
	}while(ch!=4);
}