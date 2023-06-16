#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void main()
{
	int x, y, x1, y1, x2, y2, i, dx, dy, m;
	float xi, yi;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	printf("Enter x0, y0: ");
	scanf("%d%d", &x0, &y0);
	printf("Enter x1, y1:");
	scanf("%d%d", &x1, &y1);
	x = x0;
	y= y0;
	dx = abs(x1-x0);
	dy = abs(y1-y0);
	if (dx>dy)
	{
		 m = dx;
	}
	else
	{
		m = dy;
	}
	xi =(float)(dx/m);
	yi = (float)(dy/m);
	for (k=0; k<m; k++)
	{
		putpixel(x,y,5);
		x += xi;
		y +=yi;
		delay(50);
	}
	getch();
	closegraph();


}
