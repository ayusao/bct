//find the roots using Newton-Raphson Method
#include<stdio.h>
#include<math.h>
float f(float x)
{
    //return(pow(x,3)-2*x-5);
    return (3*x - cos(x) -1);
    //1, 0.00001, 10 root= 0.607102
}
float df(float x)
{
    //return(3*x*x-2);
    return(3 + sin(x));
}
int main()
{
    int count =0, n;
    float x0, x1, e;
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error:\n");
	scanf("%f", &e);
	printf("Enter maximum iteration:\n");
	scanf("%d", &n);
    while(fabs(f(x1))>=e)
    {
        if (df(x0)<=0.0004)
        {
            printf("No solution.");
            return 0;
        }
        x1= x0 - f(x0)/df(x0);
        x0=x1;
        count++;
        if (count > n)
        {
            printf("Not Convergent.");
			return 0;
        }
    }
    printf("\nRoot is: %f", x1);
    return 0;
}