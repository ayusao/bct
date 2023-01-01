//x0, y0, xn, h or n
#include<stdio.h>
float f(float x, float y)
{
    return (x+y);
}
int main()
{
    int i;
    float x0, y0, xn, h, n,y;
    printf("Enter x0, y0, xn and n respectively: ");
    scanf("%f %f %f %f", &x0, &y0, &xn, &n);
    h= (xn-x0)/n;
    printf("\nx\t\ty\n");
    for (i=0; i<n; i++)
    {
        printf("%.3f\t\t%.3f\n", x0, y0);
        y= y0+ f(x0,y0)*h;
        x0 += h;
        y0 = y;
    }
    return 0;
}