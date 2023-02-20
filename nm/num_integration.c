//Numerical Integration
#include<stdio.h>
#include<math.h>
/*Tan-1 x 
and value from 0 to 5 is 1.3734*/
float f(float x)
{
    //return 1/(1+pow(x,2));
    //return cos(4*x);
    return (pow(x,5)+1);
}
int main()
{
    int i,n; 
    float lower, upper, h, k;
    float result, s;
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    h= (upper-lower)/n;
    s=0;
    for ( i = 1; i <= n-1; i++)
    {
        k = lower + i*h;
        s += 2*f(k);
    }
    result = h/2*(f(lower)+f(upper)+ s);
    printf("Result(Trapezoidal Rule): %.4f\n", result);
    //Simpson's 1/3 Rule
    s=0;
    for (i=1; i<=n-1; i++)
    {
        k = lower + i*h;
        if (i%2==0)
            s += 2*f(k);
        else
            s += 4*f(k);
    }
    result = h/3*(f(lower)+f(upper)+ s);    
    printf("Result(Simpson's 1/3 Rule): %.4f\n", result);
    //Simpson's 3/8 Rule 
    s=0;
    for (i=1; i<=n-1; i++)
    {
        k = lower + i*h;
        if (i%3==0)
            s+=2*f(k);
        else
            s+=3*f(k);
    }
    result = 3*h/8*(f(lower)+f(upper)+ s);    
    printf("Result(Simpson's 3/8 Rule): %.4f\n", result);
    return 0;
}