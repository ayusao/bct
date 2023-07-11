#include <stdio.h>
#include <graphics.h>

#define ymax 400    // top
#define ymin 100    // bottom
#define xmax 500    // right
#define xmin 300   // left

void clipwindow()
{
    line(xmin, ymin, xmax, ymin);
    line(xmax, ymin, xmax, ymax);
    line(xmax, ymax, xmin, ymax);
    line(xmin, ymax, xmin, ymin);
}
int cliptest(float p, float q, float *u1, float *u2)
{
    float r;
    int retval = TRUE;
    r = q / p;
    if (p < 0.0)
    {       
        if (r > *u2 )                         
            retval = FALSE;
        else if (r > *u1) //max value is to be choosen
            *u1 = r;
    }
    else if (p > 0.0)
    {
        if ( r<*u1 )                         
            retval = FALSE; 
        else if (r < *u2)
            *u2 = r;
    }
    else //p=0
    {
        if (q  < 0.0)
        {
            printf("Line is parallel and outside the clipping window \n");
            retval = FALSE; //Line is parallel and outside the clipping window
        }    
    }
    return (retval);
}
void liang(float x1, float y1, float x2, float y2)
{
    int flag =0;
    float p[4], q[4];
    float u1 = 0;
    float u2 = 1;
    float dx = x2 - x1;
    float dy = y2 - y1;

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;
    // for (int i = 0; i<4; i++){
    //     printf("p ==%f\nq == %f\n", p[i], q[i]);
    // } 
    if (cliptest(p[0], q[0], &u1, &u2))
        if (cliptest(p[1], q[1], &u1, &u2))
            if (cliptest(p[2], q[2], &u1, &u2))
                if (cliptest(p[3], q[3], &u1, &u2))
                {
                    if (u2<1.0)
                    {
                        x2 = x1 + u2 * dx;
                        printf("u2 == %f\n", u2);
                        y2 = y1 + u2 * dy; 
                    }
                    if (u1>0.0)
                    {
                        printf("u1 == %f\n", u1);
                        x1 += u1 * dx;
                        y1 += u1 * dy;
                    }
                    flag =1;
                    line(x1, y1, x2, y2); 
                }
    if (flag == 0)
    {
        printf("Line lies completely outside!");
    }
}
int main()
{
    float u, v, x, y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    u = 500;    v = 420;    x = 80;    y = 7;
    clipwindow();
    //line(u+20, v, x+20, y); // Draw the original line segment
    liang(u, v, x, y); // Clip the line segment
    getch();
    closegraph();
    return 0;
}
