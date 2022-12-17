#include<stdio.h>
#include<math.h>

int main()
{
    int n, i;
    float x, y;
    float sx, sy, sxy, xsq;

    sx = 0;
    sy = 0;
    sxy = 0;
    xsq = 0;

    printf("Number of points: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coordinates for point %d: ", i + 1);
        scanf("%f %f", &x, &y);
        sx += x;
        sy += y;
        sxy += x * y;
        xsq += x * x;
    }

    float a = sy * xsq - sx * sxy;
    float b = sy * sx - sxy * n;
    float denominator = n * xsq - sx * sx;
    a /= denominator;
    b /= denominator;

    printf("a = %.4f \t b = %.4f\n", a, b);
    printf("The equation of the line: y = %.4f + %.4fx\n", a, b);

    return 0;
}
