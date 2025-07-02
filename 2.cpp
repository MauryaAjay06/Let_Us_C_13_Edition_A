#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
void drawCircle(int xc, int yc, int x, int y){
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}
void circleBres(int xc, int yc, int r){
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x){
        if (d > 0) {
            y--; 
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        x++;
        drawCircle(xc, yc, x, y);
        delay(50);
    }
}
void midcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, 7);
	putpixel(x0 + y, y0 + x, 7);
	putpixel(x0 - y, y0 + x, 7);
	putpixel(x0 - x, y0 + y, 7);
	putpixel(x0 - x, y0 - y, 7);
	putpixel(x0 - y, y0 - x, 7);
	putpixel(x0 + y, y0 - x, 7);
	putpixel(x0 + x, y0 - y, 7);
	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}

	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}
int main()
{int xc,yc,r;
    cout<<"Enter coordinate (x,y) and radius : ";
    cin>>xc>>yc>>r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // initialize graph
    outtextxy(10, 10, " Mid point method :");
    midcircle(xc, yc, r);    // function call
    getch();
    cleardevice();
    outtextxy(10, 10, "Bresenham's algorithm:");
    circleBres(xc, yc, r);
    getch();
    closegraph();
    return 0;
}



