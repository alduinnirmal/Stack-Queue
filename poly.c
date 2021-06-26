#include<stdio.h>

struct poly
{
    float coeff;
    int exp;
}p1[5],p2[5],p3[5];

void main()
{
    int d1,d2,i=0,d=0;
    printf("\nEnter the First Polynomial Highest Degree:");
    scanf("%d",&d1);
    for(i=0;i<=d1;i++)
    {
        printf("\nEnter the Coefficient of x^%d: ",i);
        scanf("%f",&p1[i].coeff);
        p1[i].exp=i;
    }
    printf("\nEnter the Second Polynomial Highest Degree:");
    scanf("%d",&d2);
    for(i=0;i<=d2;i++)
    {
        printf("\nEnter the Coefficient of x^%d: ",i);
        scanf("%f",&p2[i].coeff);
        p2[i].exp=i;
    }
    if(d1>d2)
    {
        for(i=0;i<=d2;i++)
        {
            p3[d].coeff=p1[i].coeff+p2[i].coeff;
            p3[d].exp=p1[i].exp;
            d++;
        }
        for(i=d2+1;i<=d1;i++)
        {
            p3[d].coeff=p1[i].coeff;
            p3[d].exp=p1[i].exp;
            d++;
        }    
    }
    else
    {
        for(i=0;i<=d1;i++)
        {
            p3[d].coeff=p1[i].coeff+p2[i].coeff;
            p3[d].exp=p1[i].exp;
            d++;
        }
        for(i=d2+1;i<=d2;i++)
        {
            p3[d].coeff=p2[i].coeff;
            p3[d].exp=p2[i].exp;
            d++;
        }
    }
    printf("\nThe Resultant Polynomial is :\n%f",p3[0].coeff);
    for(i=1;i<d;i++)
        printf(" + %fx^%d",p3[i].coeff,p3[i].exp);
}
