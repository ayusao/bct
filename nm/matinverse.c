//Inverse of Matrix using Gauss Jordan Method
#include<stdio.h>
#include<math.h>
int main()
{
    float a[20][20];
    int i,j,k,n;
    float xi, temp;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of matrix: ");
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++) 
        {
            scanf("%f", &a[i][j]);
        }
    } 
    //forming augmented matrix
    for (i=1; i<=n; i++)
    {
        for (j=n+1; j<=2*n; j++)
        {
            if (j==i+n)
                a[i][j]= 1;
            else
                a[i][j]=0;
        }
    }
    //printing augmented matrix
    for(i=1; i<=n; i++)
    {
        printf("\n");
        for (j=1; j<=2*n; j++)
            printf("%.2f\t", a[i][j]);
    }
    //elementary row operation
    for (j=1; j<=n; j++)
    {
        if (fabs(a[j][j])<=0.00005)
        {
            printf("Error.\nPivot element is zero.");
            exit(0);
        }
        for (i=1; i<=n; i++)
        {
            if (i==j)
                continue;
            temp = a[i][j]/a[j][j];
            for (k=j; k<=n+1; k++)
            {
                a[i][k]= a[i][k]-(temp*a[j][k]);
            }
        }
    }
    for (i=1; i<=n; i++)
    {
        temp = a[i][i];
        for (j=1; j<=2*n; j++)
            a[i][j]= a[i][j]/temp;
    }
    printf("\nThe inverse of matrix is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\n");
        for (j=n+1; j<=2*n; j++)
            printf("%.2f\t", a[i][j]);
    }
    return 0;
}
