#include <stdio.h>
void merge(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,temp[20],k;
	while((i<=mid) && (j<=end))
	{
 		if(a[i]<a[j])
 		{
			temp[index]=a[i];
			i++;
 		}
 		else
 		{
			temp[index]=a[j];
			j++;
 		}
		index++;
	}
	if(i>mid)
	{
 		while(j<=end)
	 	{
			temp[index]=a[j];
			j++;
			index++;
 		}
	}
	else
	{
 		while(i<=mid)
 		{
			temp[index]=a[i];
			i++;
			index++;
 		}
	}
	for(k=beg;k<index;k++)
		a[k]=temp[k];
}

void merge_sort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
 		merge_sort(a,beg,mid);
		merge_sort(a,mid+1,end);
 		merge(a,beg,mid,end);
	}
}

void main()
{
	int a[20],i,n;
	printf("Enter the number of elements in the array : \n");
	scanf("%d",&n);
	printf("\n Enter the elements of the array: \n");
	for(i=0;i<n;i++)
 		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t",a[i]);
}
