//639 and 479
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

   const int originX = 300;
   const int originY = 300;
   const double PI = 3.14159265359;
	void triangle(int x, int y, int u, int v, int p, int q){
	line(x+originX, y+originY, u+originX, v+originY);
	line(u+originX, v+originY, p+originX, q+originY);
	line(p+originX, q+originY, x+originX, y+originY);
}

reflection()
{
	int b;
	printf("Reflection about::\n1.X-axis\t2.Y-axis\t3.Y=X\t4.Y=-X\n");
	scanf("%d", &b);
	return b;
}

int main()
{
   int gd = DETECT, gm;
   int x, y, u, v, p , q;
   int x1, y1;
   int a;
   float theta;
   char in;
   initgraph(&gd, &gm, "c:\\turboc3\\bgi");
   //printf("Enter the coordinates of the triangle::");
   //scanf("%d%d%d%d%d%d", &x, &y, &u, &v, &p, &q);
   x = 80;
   y = 20;
   u = 80;
   v = 55;
   p = 44;
   q = 20;
   do
   {
	clrscr();
	line(300, 0, 300, 450);
	line(0, 300, 600, 300);
	clearviewport();
	triangle(x, y, u, v, p ,q);
	printf("Select::\n1.Translation\t2.Scaling\n3.Rotation\t 4.Reflection\n");
	scanf("%d", &a);
	switch(a)
	{
		case 1:
			//translation
			//printf("enter the translation vector(x, y):");
			//scanf("%d%d", &x1,&y1);
			//triangle(x + x1, y + y1, u + x1, v + y1, p + x1, q + y1);
			triangle(x + 15, y + 10, u + 15, v + 10, p + 15, q + 10);
			break;

		case 2:
		//printf("Enter the scaling vector(x,y)::" );
			//scanf("%d%d", &x1, &y1);
			//triangle(x * x1, y * y1, u * x1, v * y1, p * x1, q * y1);
		triangle(x * 1.5, y * 1.2, u * 1.5, v * 1.2, p * 1.5, q * 1.2);
			break;
		case 3:
		//rotation
			printf("Enter the angle theta in deg::");
			scanf("%f", &theta);
			theta = (PI / 180 ) * theta;
			triangle(x * cos(theta) - y  * sin(theta),x * sin(theta) + y * cos(theta), u * cos(theta) - v  * sin(theta),u* sin(theta) + v * cos(theta),p * cos(theta) - q  * sin(theta),  p * sin(theta) + q * cos(theta));
			break;
		case 4:
			a = reflection();
			switch(a)
			{
				case 1:
					triangle(x, -y, u, -v, p , -q);
					break;
				case 2:
					triangle(-x, y, -u, v, -p , q);
					break;
				case 3:
					triangle(y, x, v, u, q, p);
					break;
				case 4:
					triangle(-y, -x, -v, -u, -q, -p);
					break;
				default:
					printf("Invalid option!");
					break;
			}
			break;
		default:
			printf("Choose a valid option!");
			break;
	}
	printf("Again?(y/n)::" );
	scanf(" %c", &in);
	}while(in == 'y' || in == 'Y');
   getch();
   closegraph();
   return 0;
}