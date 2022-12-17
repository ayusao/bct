//curve fitting(least square method)
// y= ae^bx, find the values of a and b
#include<stdio.h>
#include<math.h>
int main()
{
    float sx, sy, sxy, xsq, x, y, Y;
    int n,i;

    sx=0; sy=0; sxy=0; xsq=0;
    printf("Number of points: ");
    scanf("%d", &n);
    for ( i=0; i<n; i++)
    {
        printf("%d) x and y: ",i+1);
        scanf("%f %f", &x, &y);
        Y = log(y);
        sx +=x;
        sy += Y;
        sxy += x*Y;
        xsq += x*x;

    }
    float A = sy * xsq - sx * sxy;
    float b = sy * sx - sxy * n;
    float denominator = n * xsq - sx * sx;
    A /= denominator;
    b /= denominator;
    float a= exp(A);
    printf("a = %.4f \t b= %.4f", a, b);
    printf("\nThe equation of the exponential curve: y= %.4f e^(%.4fx)", a,b);
    return 0;
}