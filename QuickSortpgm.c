#include<stdio.h>
int a[15];
int partition(int l,int h)
{
    int i,j,temp,pivot;
    pivot=a[l];
    i=l+1;
    j=h;
    while (i<j)
    {
        while(a[i]<=pivot && i<h)
        {
            i++;
        }
        while (a[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[j];
    a[j]=a[l];
    a[l]=temp;
    return j;
}
void quicksort(int l, int h)
{
    int p;
    if (l<h)
    {
           p=partition(l,h);
           quicksort(l,p-1);
           quicksort(p+1,h);
    }
}
void main()
{
    int n,i;
    printf("Enter the number of elemnts:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for ( i = 0; i <n; i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(0,n-1);
    printf("SORTED ARRAY IS:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
}