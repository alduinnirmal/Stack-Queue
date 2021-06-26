#include<stdio.h>
#include<stdlib.h>
int pos;
struct node
{
    int data;
    struct node *link;
}*head=NULL,*ptr=NULL,*temp=NULL,*pptr=NULL;

void enter()
{
      ptr=(struct node*)malloc(sizeof(struct node));
      printf("\nEnter the Data: \n");
      scanf("%d",&ptr->data);
      ptr->link=NULL;
      temp->link=ptr;
      temp=temp->link;
}

void insertbeg()
{
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
        printf("Memory Overflow\n");
    else
    {
        printf("Enter the data : \n");
        scanf("%d",&ptr->data);
        ptr->link=head;
        head=ptr;
    }
    printf("\nElement inserted at beginning.\n");
}

void insertend()
{
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
        printf("Memory Overflow\n");
    else
    {
        if(head==NULL)
        {
            insertbeg();
        }
        else
        {
            printf("Enter the data : \n");
            scanf("%d",&ptr->data);
            temp=head;
            while(temp->link!=NULL)
                temp=temp->link;
            temp->link=ptr;
            ptr->link=NULL;
            printf("\nElement inserted at the end.\n");
        }
    }
}

void insertpos()
{
	int val,item;
	printf("Enter the data : \n");
	scanf("%d",&item);
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter the number, before which the data has to be inserted : \n");
	scanf("%d",&val);
	ptr->data=item;
	temp=head;
	while(temp->data!=val)
	{
		pptr=temp;
		temp=temp->link;
	}
	pptr->link=ptr;
	ptr->link=temp;
	printf("\nElement inserted at position.\n");
}

void disp()
{
    temp=head;
    if(temp==NULL)
        printf("List is empty\n");
    else
    {
        printf("\nLIST: \n");
        while(temp!=NULL)
        {
            printf("%d   ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void deletebeg()
{
    temp=head;
    if(temp==NULL)
        printf("The list is empty");
    else
    {
        pptr=temp->link;
        head=pptr;
    }
    printf("\nElement deleted at beginning.\n");
}

void deleteend()
{
    temp=head;
    if(temp->link==NULL)
        printf("The list is empty");
    else
    {
        while(temp->link!=NULL)
        {
            pptr=temp;
            temp=temp->link;
        }
        pptr->link=NULL;
    }
    printf("\nElement deleted at end.\n");
}

void deleteanypos()
{
    temp=head;
    if(temp==NULL)
        printf("The list is empty");
    else
    {
        printf("Enter the element to be deleted : \n");
        scanf("%d",&pos);
        if(temp->data==pos)
            deletebeg();
        else
        {
            temp=head;
            pptr=head;
            while(temp->data!=pos)
            {
                pptr=temp;
                temp=temp->link;
                if(temp==NULL)
                {
                    printf("\nNo element found\n");
                    return;
                }
            }
            pptr->link=temp->link;
        }
    }
}

void search()
{
     int item,cnt=1;
     printf("Enter the element to be searched : \n");
     scanf("%d",&item);
     temp=head;
     while(temp->data!=item)
     {
         cnt++;
         temp=temp->link;
         if(temp==NULL)
         {
            printf("Element not found");
            return;
         }
     }
     printf("The element is at position %d in the list ",cnt);
}

void main()
{
      int ch,pos,item;
      ptr=(struct node*)malloc(sizeof(struct node));
      printf("\nEnter the Data: \n");
      scanf("%d",&ptr->data);
      ptr->link=NULL;
      head=ptr;
      temp=ptr;
      do
      {
          printf("\n1.Enter another data\n0.Stop\n\nEnter the choice:\n");
          scanf("%d",&ch);
          switch(ch)
          {
            case 1:
                    enter();
                    break;
            case 0:
                    break;
            default:
                    printf("Invalid Choice");
                    break;
          }
      }while(ch!=0);
      printf("\nList is created.\n\n");
      printf("1.INSERTION AT BEGINNING\n2.INSERTION AT END\n3.INSERTION AT SPECIFIED POSITION");
      printf("\n4.DELETION AT BEGINNING\n5.DELETION AT END\n6.DELETION AT SPECIFIED POSITION");
      printf("\n7.SEARCH THE LIST");
      printf("\n8.DISPLAY THE LIST \n9.EXIT\n");
      do
      {
            printf("\nEnter the choice : \n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                        insertbeg();
                        break;
                case 2:
                        insertend();
                        break;
                case 3:
                        insertpos();
                        break;
                case 4:
                        deletebeg();
                        break;
                case 5:
                        deleteend();
                        break;
                case 6:
                        deleteanypos();
                        break;
                case 7:
                        search();
                        break;
                case 8:
                        disp();
                        break;
                case 9:
                        exit(0);
                        break;
                default:
                        printf("Invalid choice\n");
                        break;
            }
      }while(ch!=9);
}
