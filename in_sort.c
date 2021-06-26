#include<stdio.h>
int i,j,temp,a[20],n;
void insertion(int a[], int n)
{

	for(i=1; i<n; i++)
	{
		temp = a[i];
		j = i-1;
		while(a[j]>temp && j>=0)
		{
			
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}

}
void main()
{
	printf("Enter the Number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);	
	}
	insertion(a,n);
	printf("After insertion sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i] );
	}
}