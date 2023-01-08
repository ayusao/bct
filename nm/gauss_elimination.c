//Gauss Elimination Method
#include<stdio.h>
#include<math.h>
int main()
{
    float a[20][20], x[20];
    int i,j,k,n;
    float xi, temp, s;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of augmented matrix: ");
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n+1; j++)
        {    scanf("%f", &a[i][j]);}
    }
    //upper triangular matrix
    for (j=1; j<=n; j++)
    {
        if (fabs(a[j][j])<=0.00005)
        {
            printf("Error.\nPivot element is zero.");
            exit(0);
        }
        for (i=j+1; i<=n; i++)
        {
            if (i==j)
                continue;
            temp = a[i][j]/a[j][j];
            for (k=j; k<=n+1; k++)
            {
                a[i][k] = a[i][k]-(temp*a[j][k]);
            }
        }
    }
    x[n]=a[n][n+1]/a[n][n];
    //back substitution method
    for (i=n-1; i>=1; i--)
    {
        s=0; 
        //x[i]=a[i][i+1]/a[i][i];
        //printf("%d\n", i);
        for (j=i+1; j<=n; j++)
        {
            //x[i]=a[j][j+1]/a[j][j];
            s += a[i][i+1]*x[j];
        }
        x[i]= (a[i][n+1]-s)/a[i][i];
        //printf("x%d = %.2f\n", i, x[i]);
    }
    for(i=1; i<=n; i++)
    {
        printf("x%d = %.2f\n", i, x[i]);
    }
    //printf("x%d = %.2f\n", n, x[n]);
    return 0;
}
