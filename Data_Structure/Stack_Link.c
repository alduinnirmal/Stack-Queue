#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};struct node *top = NULL;
void push(int num)
{
	struct node *newnode;
	printf("Enter the element\n");
	scanf("%d",&num);
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->link = top;
	top = newnode;
}
void pop()
{
	struct node *temp;
	temp = top;
	if(top == NULL)
		printf("Stack is Empty\n");
	else
	{
		printf("Poped element = %d\n",temp->data );
		top = top->link;
	}

}
void display()
{
	struct node *temp;
	temp = top;
	if(top == NULL)
		printf("Stack is Empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp = temp->link;
		}
	}
}
void main()
{	
	int ch,num;
	do{
	printf("Enter the choice\n1.PUSH\t2.POP\n3.DISPLAY\t4.EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:push(num);
			break;
		case 2:pop();
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