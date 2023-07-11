//NOT WOR$KING
#include <stdio.h>
#include <graphics.h>

#define ymax 150    // top
#define ymin 250    // bottom
#define xmax 350    // right
#define xmin 250    // left

void liang(int x1, int y1, int x2, int y2)
{
    int p[4], q[4];
    float x1_clip, y1_clip, x2_clip, y2_clip;
    
    int dx = x2 - x1;
    int dy = y2 - y1;

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    float u1 = 0, u2 = 1;

    for (int i = 0; i < 4; i++)
    {
        if (p[i] < 0)
        {
            float r = (float)q[i] / p[i];
            printf("r value %d ::: %f\n ",i, r);
            if (r > u1) //max value is to be choosen
                u1 = r;
                printf("u1  pi < 0\t%f\n", u1);
        }
        else if (p[i] > 0)
        {
            float r = (float)q[i] / p[i];
            printf("r value %d ::: %f\n ",i, r);
            if (r < u2)
                u2 = r;
                printf("u2  pi > 0\t%f\n", u2);
        }
        else
        {
            if (q[i] < 0)
            {
                printf("Line is parallel and outside the clipping window \n");
                return; // Rejected; Line is parallel and outside the clipping window
            }
            printf("pi == 0\n");

              
        }
        
    }
    // if (u1 > u2)
    // {
    //     printf("Line is completely outside the clipping window\n");
    //     return; // Line is completely outside the clipping window
    // }
    x1_clip = x1 + u1 * dx;
    y1_clip = y1 + u1 * dy;
    x2_clip = x1 + u2 * dx;
    y2_clip = y1 + u2 * dy; 

    line(x1_clip, y1_clip, x2_clip, y2_clip);
    printf("%f\t%f\t%f\t%f\n", x1_clip, y1_clip, x2_clip, y2_clip);
}
int main()
{
    int u, v, x, y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    u = 175;    v = 175;    x = 325;    y = 225;

    // Clipping window
    line(xmin, ymin, xmax, ymin);
    line(xmax, ymin, xmax, ymax);
    line(xmax, ymax, xmin, ymax);
    line(xmin, ymax, xmin, ymin);

    //line(u, v, x, y); // Draw the original line segment

    liang(u, v, x, y); // Clip the line segment

    getch();
    closegraph();
    return 0;
}
