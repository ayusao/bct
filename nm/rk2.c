//RK2
#include<stdio.h>
float f(float x, float y)
{
    return (x+y);
}
int main()
{
    float x0, y0, xn, n, h;
    float k1, k2, k3, k4, k, y;
    printf("Enter x0, y0, xn and n respectively: ");
    scanf("%f %f %f %f", &x0, &y0, &xn, &n);
    h= (xn-x0)/n;
    printf("\nx\t\ty\n");
    for (x0; x0<=xn; x0+=h)
    {
        printf("%.4f\t\t%.4f\n\n", x0, y0);
        k1= h*f(x0, y0);
        k2= h*f(x0+h/2, y0+k1/2);
        k= (k1+k2)/2;
        y= y0+k;
        y0= y;
    }
    return 0;
}