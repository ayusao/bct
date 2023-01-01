//euler, rk4, rk2 allinone
#include<stdio.h>
float f(float x, float y)
{
    return (x+y);
}
void euler(float x0, float y0, float xn, float h)
{
    float y;
    printf("By Euler Method:\n");
    printf("\nx\t\ty\n");
    for (x0; x0<=xn; x0+=h)
    {
        printf("%.4f\t\t%.4f\n", x0, y0);
        y= y0+ f(x0,y0)*h;
        y0 = y;
    }
}
void rk2(float x0, float y0, float xn, float h)
{
    float k1, k2,k,y;
    printf("By RK 2 Method:\n");
    printf("\nx\t\ty\n");
    for (x0; x0<=xn; x0+=h)
    {
        printf("%.4f\t\t%.4f\n", x0, y0);
        k1= h*f(x0, y0);
        k2= h*f(x0+h/2, y0+k1/2);
        k= (k1+k2)/2;
        y= y0+k;
        y0= y;
    }
}
void rk4(float x0, float y0, float xn, float h)
{
    float k1, k2, k3, k4, k, y;
    printf("By RK 4 Method:\n");
    printf("\nx\t\ty\n");
    for (x0; x0<=xn; x0+=h)
    {
        printf("%.4f\t\t%.4f\n", x0, y0);
        k1= h*f(x0, y0);
        k2= h*f(x0+h/2, y0+k1/2);
        k3= h*f(x0+h/2, y0+k2/2);
        k4= h*f(x0+h, y0+k3);
        k= (k1+2*k2+2*k3+k4)/6;
        y= y0+k;
        y0= y;
    }
}
int main()
{
    float x0, y0, xn, n, h;
    
    printf("Enter x0, y0, xn and n respectively: ");
    scanf("%f %f %f %f", &x0, &y0, &xn, &n);
    h= (xn-x0)/n;
    //by euler
    euler(x0, y0,xn, h);
    //by rk2 method
    rk2(x0, y0,xn, h);
    //for rk4 method
    rk4(x0, y0,xn, h);
    return 0;
}