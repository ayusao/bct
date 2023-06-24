//Midpoint algorithm for circle
#include<stdio.h>
#include<graphics.h>
#include<math.h>
//#include<dos.h>

int main()
{
	int h, k, r, xk, yk, x, y, p, pk, i;
	int xp, yp;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	printf("Enter center h, k and radius: ");
	scanf("%d%d%d", &h, &k, &r);
	x = 0;
	y = r;
	p = 1-r;
	xk = x;
	yk = y;
	while (xk<=yk)
	{   	
		x = xk;
		y = yk;

		xp = x+h;
		yp = y+k;
		putpixel(xp,yp,5);
		delay(50);

		putpixel(h+x, k-y,5);
		delay(50);

		putpixel(h-x, k+y,5);
		delay(50);

		putpixel(h-x, k-y,5);
		delay(50);

		putpixel(h+y, k+x,5);
		delay(50);

		putpixel(h-y, k+x,5);
		delay(50);

		putpixel(h+y, k-x,5);
		delay(50);

		putpixel(h-y, k-x,5);
		delay(50);
		if(p<=0)
		{
			xk++;
			p = p+2*xk+1;
		}
		else
		{
			xk++;
			yk--;
			p = p+2*xk-2*yk+1;
		}
	}
	getch();
	closegraph();
    return 0;
}