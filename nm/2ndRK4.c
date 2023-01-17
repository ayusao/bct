//2nd order Ordinary Differential Equation by RK4 Method
#include<stdio.h>
float f(float x, float y, float z)
{
    return z;
}
float g(float x, float y, float z)
{
    return (3*x*x-2*z);
}
int main()
{
    float x0, y0, z0, xn, n, h;
    float k1, k2, k3, k4, k, y;
    float l1, l2, l3, l4, l, z;
    printf("Enter x0, y0, z0, xn and n respectively: ");
    scanf("%f %f %f%f %f", &x0, &y0, &z0, &xn, &n);
    h= (xn-x0)/n;
    printf("\nx\t\ty\t\tz\n");
    for (x0; x0<=xn; x0+=h)
    {
        printf("%.4f\t\t%.4f\t\t%.4f\n\n", x0, y0, z0);
        k1= h*f(x0, y0, z0);
        l1= h*g(x0, y0, z0);
        k2= h*f(x0+h/2, y0+k1/2, z0+l1/2);
        l2= h*g(x0+h/2, y0+k1/2, z0+l1/2);
        k3= h*f(x0+h/2, y0+k2/2, z0+l2/2);
        l3= h*g(x0+h/2, y0+k2/2, z0+l2/2);
        k4= h*f(x0+h, y0+k3, z0+l3);
        l4= h*g(x0+h, y0+k3, z0+l3);
        k= (k1+2*k2+2*k3+k4)/6;
        l= (l1+2*l2+2*l3+l4)/6;
        y0= y0+k;
        z0= z0+l;
        //y0= y;

    }
    return 0;
}