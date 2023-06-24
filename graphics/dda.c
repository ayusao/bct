#include<stdio.h>
#include<graphics.h>
#include<math.h>
//#include<dos.h>

int main()
{
	int x, y, x1, y1, x2, y2, dx, dy, m, k, po, p, pi, a, b;
	int xi, yi;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	printf("Enter x1, y1: ");
	scanf("%d%d", &x1, &y1);
	printf("Enter x2, y2:");
	scanf("%d%d", &x2, &y2);
	x = x1;
	y= y1;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	if (x2>x1)
	{
		 a = 1;
	}
	else
	{
		a = -1;
	}
	if (y2>y1)
	{	b = 1;
	}
	else
	{	b= -1;}

	if (dx>dy)
	{
		p = 2*dy - dx;

		for (k=0; k<dx; k++)
		{
			putpixel(x,y,5);
			delay(20);
			if (p<0)
			{
			   x = x+a;
			   y = y;
			   p = p+2*dy;
			}
			else
			{
				x = x+a;
				y = y+b;
				p = p+2*dy-2*dx;
			}
		}
	}


	else
	{
		p = 2*dx -dy;
		for (k=0; k<dy; k++)
		{
			putpixel(x,y,5);
			delay(20);
			if (p<0)
			{
			   x = x;
			   y = y+b;
			   p = p+2*dx;
			}
			else
			{
				x = x+a;
				y = y+b;
				p = p+2*dx-2*dy;
			}
		}
	}
	getch();
	closegraph();
    return 0;
}


