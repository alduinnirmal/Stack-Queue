#include<stdio.h>
int i,n,temp,j,a[20];
void selectionsort(int a[],int n)
{
    int smallest;
    for(i=0;i<n-1;i++)
    {
	    smallest=i;
        for(j=i+1;j<n;j++)
          if(a[smallest]>a[j])
                smallest=j;
        if(smallest!=i)
		{
            temp=a[i];
            a[i]=a[smallest];
            a[smallest]=temp;
        }

    }
}
void main()
{
    printf("Enter the number of elements in the array: \n");
	scanf("%d",&n);
	printf("\n Enter the elements of the array: \n");
	for(i=0;i<n;i++)
 		scanf("%d",&a[i]);
	selectionsort(a, n);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t",a[i]);
}

