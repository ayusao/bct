//finding roots of a function using secant method
#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (x*x*x+3*x*x-5);
    //return (x*sin(x)+cos(x));
}
int main()
{
    float a,b,c;
    int count=0;
    printf("Enter a and b: ");
    scanf("%f %f", &a, &b);
    if (f(a)==f(b))
    {
        printf("Error!!");
        exit(0);
    }
    while(fabs(f(c))>=0.00005)
    {
        c = (a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        count++;
    }
    if (fabs(f(c))<=0.0005)
    {
        printf("Root = %.5f", c);
        return 0;
    }
    
    if (count>=1000)
    {
        printf("Root cannot be estimated.");
        return 0;
    }
     
}