//find the roots using Newton-Raphson Method
#include<stdio.h>
#include<math.h>
float f(float x)
{
    //return(pow(x,3)-3*x*x-5);
    //return (3*x - cos(x) -1);
    return ((x*sin(x)+cos(x)));
}
float df(float x)
{
    //return(3*x*x-6*x);
    //return(3 + sin(x));
    return (x*cos(x));
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
    do
    {
        if (df(x0)==0)
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
    }while(fabs(f(x1))>=e);
    printf("\nRoot is: %.5f", x1);
    return 0;
}