#include<stdio.h>
int top=-1, q[20], stack[20], arr[20][20], front=-1, rear=-1, visited[20]={};

void enqueue(int item)
{
 if(rear==19)
  printf("Queue if full ");
 else
 {
   if(rear==-1)
   {
    q[++rear]=item;
    front++;
   }

   else
    q[++rear]=item;
 }
}

int dequeue()
{
 int x;
 if((front>rear)||(front==-1))
  return 0;
 else
 {
   x=q[front++];
   return x;
 }
}

void push(int item)
{
 if (top==19)
  printf("Stack overflow");
 else
  stack[++top]=item;
}

int pop()
{
 int x;
 if(top==-1)
  return 0;
 else
 {
   x=stack[top--];
   return x;
 }
}


void bfs(int x,int n)
{
  int i;
  enqueue(x);
  visited[x]=1;
 
   while(!(front==-1 || front>rear))
   {
     x = dequeue();
     printf("%d ",x);
     visited[x]=2;
     for(i=1;i<=n;i++)
     {
       if(arr[x][i]==1 && visited[i]== 0)
       {
         enqueue(i);
         visited[i]=1;
       }
     }
   }
   printf("\n");
}
void dfs(int x,int n)
{
    int i;
    push(x);
    while(top!=-1)
    {
        x=pop();
        if(visited[x]==0)
        {
            printf("%d ",x);
            visited[x]=1;
        }
        for(i=n;i>=1;i--)
        {
            if(arr[x][i]==1 && visited[i]==0)
            push(i);
        }
    }
    printf("\n");
}

void main()
{
  int i,j,n,ch,s;
  printf("\n BFS and DFS graph traversals!\n\n Enter the number of veitices : ");
  scanf("%d",&n);
  printf("\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf(" Enter 1 if %d has an edge with %d else 0 : ",i,j);
      scanf("%d",&arr[i][j]);
    }
  }
  printf("\n Adjacency matrix : \n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf(" %d",arr[i][j]);
    }
    printf("\n");
  }
  do
  {
    printf("\n 1-BFS\n 2-DFS \n 0-EXIT \n Enter your choice : ");
    scanf("%d",&ch);
    for(i=0;i<=n;i++)
    {
      visited[i]=0;
    }
    if(ch==1 || ch==2)
    {
      printf("\n Enter the stating vertex : ");
      scanf("%d",&s);
    }
    switch(ch)
    {
      case 1:  printf("\n The elements are : ");
               bfs(s,n);
               break;

      case 2:  printf("\n The elements are : ");
               dfs(s,n);
               break;

      case 0:  printf("\n Exiting!!!");
               break;

      default: printf("\n Wrong choice!\n");
               break;
    }

   }while(ch!=0);
}
