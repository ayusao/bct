//Mid-point ellipse algorithm
#include<stdio.h>
#include<graphics.h>
#include<math.h>
//#include<dos.h>

int main()
{
	float h, k, xk, yk, x, y, p1, p2;
	float xp, yp, a, b;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	printf("Enter center h, k and radius a and b: ");
	scanf("%f%f%f%f", &h, &k, &a, &b);
	x = 0;
	y = b;
//for region 1
	p1 = b*b-b*a*a+a*a/4;
	xk = x;
	yk = y;
	do
	{
		x = xk;
		y = yk;

		xp = x+h;
		yp = y+k;
		putpixel(xp,yp,2);
		delay(50);

		putpixel(h+x, k-y,2);
		delay(50);

		putpixel(h-x, k+y,2);
		delay(50);

		putpixel(h-x, k-y,2);
		delay(50);

		if(p1<0)
		{
			xk++;
			p1 = p1+ 2*xk*b*b +b*b;
		}
		else
		{
			xk++;
			yk--;
			p1 = p1+2*xk*b*b-2*yk*a*a+b*b;
		}
	}while (2*b*b*xk<=2*a*a*yk);
	//for region 2
	p2 = (x+0.5)*(x+0.5)*b*b + (y-1)*(y-1)*a*a - a*a*b*b ;
	do
	{
		x = xk;
		y = yk;

		xp = x+h;
		yp = y+k;
		putpixel(xp,yp,8);
		delay(50);

		putpixel(h+x, k-y,8);
		delay(50);

		putpixel(h-x, k+y,8);
		delay(50);

		putpixel(h-x, k-y,8);
		delay(50);

		if(p2>0)
		{
			yk--;
			p2 = p2-2*yk*a*a+a*a;
		}
		else
		{
            xk++;
            yk--;
			p2 = p2+2*xk*b*b-2*yk*a*a+a*a;
		}
	}while (y>=0);
	getch();
	closegraph();
    return 0;
}
