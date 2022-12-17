#include<stdio.h>
#include<math.h>
float func(float x)
{
    return(x*sin(x)+cos(x));
}
int main()
{
    int count=0, solution=1;
    float a,b,c, root;
    //solution=1;
    //count=0;
    printf("Enter the values of a and b: ");
    scanf("%f %f",&a,&b);
    if (func(a)*func(b)>0)
        solution=0;
    while(fabs(func(c))>0.0005)
    {
        count++;
        c=(a+b)/2;
        if ((func(a)*func(c))<0)
            b=c;
        else
            a=c;
        if (count>100)
        {
            solution =0;
            break;
        }

    }
        if (solution==1)
        {
            root=c;
            printf("Root= %f", root);
            return 0;
        }
        else
            printf("No solution exists for this problem.");
            return 0;

}
