#include <stdio.h>
int i,n,temp,j,a[20];
void insertion_sort(int a[], int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
 		temp=a[i];
 		j=i-1;
 		while((temp<a[j]) && (j>=0))
 		{
 			a[j+1]=a[j];
			j--;
 		}
 		a[j+1] = temp;
	}
}
void main()
{
	printf("Enter the number of elements in the array: \n");
	scanf("%d",&n);
	printf("\n Enter the elements of the array: \n");
	for(i=0;i<n;i++)
 		scanf("%d",&a[i]);
	insertion_sort(a, n);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t",a[i]);
}

