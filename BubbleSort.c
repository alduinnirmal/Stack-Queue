#include <stdio.h>
int i,n,temp,j,a[20];
void bubblesort(int a[],int n)
{
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
 			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}		
}
void main()
{
	printf("\n Enter the number of elements in the array : ");
	scanf("%d",&n);
	printf("\n Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubblesort(a, n);
	printf("\n The sorted array is :\n");
	for(i=0;i<n;i++)
		printf("  %d\t", a[i]);
}
