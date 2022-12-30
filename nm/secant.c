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
    float e=0.0005;
    int count=0;
    printf("Enter a and b: ");
    scanf("%f %f", &a, &b);
    do
    {
        if (f(a)==f(b))
        {
            printf("Error!!");
            return 0;
        }
        c = (a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        count++;
        if (count>=1000)
        {
            printf("Root cannot be estimated.");
            return 0;
        }
    }while(fabs(f(c))>=e);
    printf("Root = %.5f", c);
    return 0;    
}