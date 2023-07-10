#include <stdio.h>
#include <graphics.h>

#define top 150    // ymax
#define bottom 250 // ymin
#define right 350  // xmax
#define left 250   // xmin

int assignregioncode(int x, int y)
{
    int code = 0;

    if (x < left)
        code |= 1;   // Set bit 1 to 1 for left
    else if (x > right)
        code |= 2;   // Set bit 2 to 1 for right
    if (y < top)
        code |= 4;   // Set bit 3 to 1 for top
    else if (y > bottom)
        code |= 8;   // Set bit 4 to 1 for bottom

    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2)
{
    float m;
    int code1 = assignregioncode(x1, y1);
    int code2 = assignregioncode(x2, y2);
    // Clipping logic
    while ((code1 | code2) != 0) // logical or
    {
        if ((code1 & code2) != 0) // logical and
        {
            // Line is completely outside the clipping window
            return;
        }
        int code = (code1 != 0) ? code1 : code2;
        int x, y;
        // Find intersection point
        m = (float)(y2 - y1) / (x2 - x1);

        if (m == 0) {
            // Horizontal line, handle separately
            if (code & 1) // Left boundary
            {
                x = left;
                y = y1;
            }
            else if (code & 2) // Right boundary
            {
                x = right;
                y = y1;
            }
        }
        else {
            if (code & 1) // Left boundary
            {
                x = left;
                y = y1 + m * (left - x1);
            }
            else if (code & 2) // Right boundary
            {
                x = right;
                y = y1 + m * (right - x1);
            }
            else if (code & 4) // Top boundary
            {
                y = top;
                x = x1 + (top - y1) / m;
            }
            else // Bottom boundary
            {
                y = bottom;
                x = x1 + (bottom - y1) / m;
            }
        }
        // Replace the outside point with the intersection point
        if (code == code1)
        {
            x1 = x;
            y1 = y;
            code1 = assignregioncode(x1, y1);
        }
        else
        {
            x2 = x;
            y2 = y;
            code2 = assignregioncode(x2, y2);
        }
    }
    // The line is completely or partially inside the clipping window
    // Draw the clipped line segment
    line(x1, y1, x2, y2);
}

int main()
{
    int u, v, x, y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    u = 100;    v = 100;    x = 500;    y = 450;
    // Clipping window
    line(left, bottom, right, bottom);
    line(left, top, right, top);
    line(left, top, left, bottom);
    line(right, top, right, bottom);

    cohenSutherland(u, v, x, y);
    //line(u, v, x, y);
    getch();
    closegraph();
    return 0;
}
