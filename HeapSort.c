#include<stdio.h>
int a[20],i,n,temp;
void heapify(int a[],int n,int i)
{
	int lar=i,l=2*i+1,r=2*i+2;
	if(l<n && a[l]>a[lar])
		lar=l;
	if(r<n && a[r]>a[lar])
		lar=r;
	if(lar!=i)
	{
		temp=a[i];
		a[i]=a[lar];
		a[lar]=temp;
		heapify(a,n,lar);
	}
}
void heap_sort(int a[],int n)
{
	for(i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(i=n-1;i>=0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(a,i,0);
	}
	
}
void main()
{
	printf("Enter the number of elements in the array : \n");
	scanf("%d",&n);
	printf("\n Enter the elements of the array: \n");
	for(i=0;i<n;i++)
 		scanf("%d",&a[i]);
	heap_sort(a,n);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t",a[i]);
}
