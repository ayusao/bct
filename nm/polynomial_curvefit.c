//polynomial curve fitting
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,d,i,j,k;
    float a[10][10], x[10] ,y[10];
    float s, temp;
    printf("Enter the order and degree: ");
    scanf("%d%d", &n, &d);
    if (d>=n)
    {
        printf("d cannnot be greater than n.");
        exit(0);
    }
    for (i=0; i<n; i++)
    {
        printf("x[%d] and y[%d]:\n", i, i);
        scanf("%f%f", &x[i], &y[i]);
    }
    for (i=0; i<=d; i++)
    {        
        for (j=0; j<=d; j++)
        {
            a[i][j]=0;
            for (k=0; k<=n-1; k++)
            {            
                a[i][j] += pow(x[k], i+j);
            }
        }
        a[i][d+1] = 0;
        for (k=0; k<=n-1; k++)
        {            
            a[i][d+1] += (pow(x[k], i) * y[k]); 
        }
        //checking the augmented matrix
        printf("\n");
        for (j=0; j<=d+1; j++)
        {
            printf("%.2f\t", a[i][j]);
        }
    }
    for (j=0; j<=d; j++)
    {
        if (fabs(a[j][j])<=0.00005)
        {
            printf("Error.\nPivot element is zero.");
            exit(0);
        }
        for (i=0; i<=d; i++)
        {
            if (i==j)
                continue;
            temp = a[i][j]/a[j][j];
            for (k=j; k<=d+1; k++)
            {
                a[i][k]= a[i][k]-(temp*a[j][k]);
            }
        }
    }
    printf("\nThe coefficients of the polynomial are:\n");
    for (i=0; i<=d; i++)
    {
        printf("x%d = %.2f\n", i+1, (a[i][d+1]/a[i][i]));
    }
    return 0;

}