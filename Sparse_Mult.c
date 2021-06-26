#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct sparse
 {
  int row;
  int col;
  int val;
 }a[30],b[30],p[30];
int COMPARE(int x,int y)
 {
  int i;
  if(x>y)
     i=1;
  else if(x<y)
     i=-1;
  else
     i=0;
  return i;
 }
void main()
 {
  int i,j,c,r,tot1,tot2,tot3=0,r1,c1,c2,row_beg=1,s=0;
  printf("\nEnter the r1 and c1 number non zero elements of first matrix:");
  scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);
  printf("\nEnter row,column non zero elements of the first matrix:");
  for(i=1;i<=a[0].val;i++)
    {
     scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
    }
    
  printf("\nThe first matrix is:\n");
  printf("Row\tcoloumn\tvalue\n");
  for(i=0;i<=a[0].val;i++)
    {
     printf("%d\t%d\t%d\t",a[i].row,a[i].col,a[i].val);
     printf("\n");
    }
  printf("\nEnter the r2 and c2 number non zero elements of second matrix:");
  scanf("%d%d%d",&b[0].row,&b[0].col,&b[0].val);
  printf("\nEnter row column non zero elements of transposed second matrix:");
  for(i=1;i<=b[0].val;i++)
    {
     scanf("%d%d%d",&b[i].row,&b[i].col,&b[i].val);
     }
     
  printf("\nThe second matrix is:\n");
  printf("Row\tcoloumn\tvalue\n");
    for(i=0;i<=b[0].val;i++)
    {
     printf("%d\t%d\t%d\t",b[i].row,b[i].col,b[i].val);
     printf("\n");
    }
 tot2=b[0].val;
 r1=a[0].row;
 c1=a[0].col;
 tot1=a[0].val;
 c2=b[0].col;
 r=a[1].row;
 a[tot1+1].row=r1;
 b[tot2+1].row=c2;
 b[tot2+1].col=0;
 for(i=1;i<=tot1;)
   {
     c=b[1].row;
     for(j=1;j<=tot2+1;)
        {
         if(a[i].row!=r)
           {
            tot3++;
            p[tot3].row=r;
            p[tot3].col=c;
            p[tot3].val=s;
            i=row_beg;
            s=0;
            
              for(;b[j].row==c;j++)
              ;
              c=b[j].row;
           }
          else if(b[j].row!=c)
            {
              tot3++;
              p[tot3].row=r;
              p[tot3].col=c;
              p[tot3].val=s;
              s=0;
              i=row_beg;
              c=b[j].row;
              
             }
           else switch (COMPARE (a[i].col,b[j].col))
               {
                 case -1:
                         i++;
                         break;
                 case 0:
                         s=s+(a[i++].val*b[j++].val);
                         break;
                 case 1:
                         j++;
               }
           }
         for(;a[i].row==r;i++)
             ;
           row_beg=i;
           r=a[i].row;
        }
       p[0].row=r1;
       p[0].col=c1;
       p[0].val=tot3;
       printf("\nThe product is:\n");
       printf("Row\tcoloumn\tvalue\n");
       for(i=0;i<=tot3;i++)
         {
           printf("%d\t%d\t%d\t",p[i].row,p[i].col,p[i].val);
           printf("\n");
         }
   }
