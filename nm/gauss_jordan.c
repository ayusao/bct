//Gauss Jordan Method
#include<stdio.h>
//#include<stdlib.h>
#include<math.h>
int main()
{
    float a[20][20];
    int i,j,k,n;
    float xi, temp;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix: ");
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n+1; j++) //augmented
        {
            scanf("%f", &a[i][j]);
        }
    }
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
    printf("\n");
    for (i=1; i<=n; i++)
    {
        printf("x%d = %.2f\n", i, (a[i][n+1]/a[i][i]));
    }
    return 0;
}
