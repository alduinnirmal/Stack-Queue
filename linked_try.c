#include<stdio.h>
#include<stdlib.h>
struct snode
{
	int roll;
	char name[20];
	struct snode* link;
};
void main()
{
	struct snode* student=NULL,*temp,*head;
	int n, i=0;
	printf("Enter Number of Students:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Details of %dth Student:\n",i+1);
	student=(struct snode*)malloc(sizeof(struct snode));
	student->link=NULL;
	printf("ROLL NO:\n");
	scanf("%d",&student->roll);
	printf("NAME: \n");
	scanf("%s",student->name);
	if(i==0)
	{
		head=student;
		temp=student;
	}
	else
	{
		temp->link=student;
		temp=student;
	}
	}
	temp=head;
	i=0;
	while(temp!=NULL)
	{
	printf("\nDetails of %dth Student:\n",i+1);
	i++;
	printf("Name=%s\tRoll NO=%d\n",temp->name,temp->roll);
	printf("\n");
	temp=temp->link;
	}
	
}
