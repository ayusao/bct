//Power method to find eigen values and eigen vector
#include<stdio.h>
#include<math.h>
int main()
{
    int n, i, j;
    float a[10][10], x[10], y[10], z[10], d[10];
    float l, e;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Elements of the matrix: \n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("Elements of the vector matrix: \n");
    for (i=0; i<n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }
    do{
        //multiplication of matrices
        for (i=0; i<n; i++)
        {
            z[i]=0; 
            for (j=0; j<n; j++)
            {
                z[i] += a[i][j] * x[j];
            }
        }
        for(i=0; i<n; i++)
        {
            l = fabs(z[0]);
            if (fabs(z[i])>l)
            {
                l= z[i];
            }
        }
        for (i=0; i<n; i++)
        {
            y[i] = z[i]/l;
           d[i] = fabs(y[i]-x[i]);
            e = d[0];
            if (d[i]>e)
            {
                e= d[i];
            }
        }
        for (i=0; i<n; i++)
        {
            
        }
        for (i=0; i<n; i++)
        {
            x[i] = y[i];
        }


    }while(e>0.00005);
    printf("\nLargest eigen value: %.3f\nEigen vector is:\n", l);
    for(i=0; i<n; i++)
    {
        printf("%.3f\n", y[i]);
    }
    return 0;
}