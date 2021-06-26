#include<stdio.h>
#include<stdlib.h>
int n=1,value,val;
struct node
{
	int data;
	struct node *next;
}*new,*copy,*head,*h,*end,*t,*temp,*temp1;
void main()
{
	while(n!=0)
	{
		new=(struct node *)malloc(sizeof(struct node));
		printf("Enter the value:");
		scanf("%d",&value);
		new->data=value;
		new->next=NULL;
		if(head==NULL)
		{
			head=new;
			end=new;
		}
		else
		{  
			end->next=new;
			end=new;
		}
		printf("\nEnter '0' to EXIT,'1' to continue\n");
		printf("\nEnter your choice:");
		scanf("%d",&n);
		printf("\n");
	}
	temp=head;
	printf("\nList :");
	while(temp!=NULL)
	{
		val=temp->data;
		printf("%d ",val);
		if(val%2==0)
		{
			copy=(struct node *)malloc(sizeof(struct node));
			copy->data=val;
			copy->next=NULL;
			if(h==NULL)
			{
				h=copy;
				t=copy;
			}
			else
			{
				t->next=copy;
				t=copy;
			}

		}
		temp=temp->next;  
	}
	printf("\n\nEven elements are :");    
	temp1=h;
	while(temp1!=NULL)
	{
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
	printf("\n");
}
