#include <stdio.h>
int partition(int a[],int beg,int end)
{
	int left,right,temp,piv,flag;
	piv=left=beg;
	right=end;
	flag=0;
	while(flag!=1)
	{
		while((a[piv]<=a[right])&&(piv!=right))
			right--;
		if(piv==right)
 			flag=1;
 		else if(a[piv]>a[right])
 		{
 			temp=a[piv];
 			a[piv]=a[right];
 			a[right]=temp;
 			piv=right;
 		}
		if(flag!=1)
 		{
			while((a[piv]>=a[left])&&(piv!=left))
				left++;
 			if(piv==left)
				flag=1;
 			else if(a[piv]<a[left])
 			{
 				temp=a[piv];
				a[piv]=a[left];
				a[left]=temp;
				piv=left;
 			}
 		}
	}
	return piv;
}

void quick_sort(int a[],int beg,int end)
{
	int piv;
	if(beg<end)
	{
 		piv=partition(a,beg,end);
		quick_sort(a,beg,piv-1);
		quick_sort(a,piv+1,end);
	}
}

void main()
{
	int a[20],i,n;
	printf("\n\tQUICK SORT\n Enter the number of elements in the array: ");
	scanf("%d",&n);
	printf("\n Enter the elements of the array: \n");
	for(i=0;i<n;i++)
	 	scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t",a[i]);
}

