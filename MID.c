#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>                                                                                     #include<graphics.h>
int xc,yc;
void symmetric(int x,int y)
{
	putpixel(xc+x,yc+y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);
	putpixel(xc+y,yc+x,15);
	putpixel(xc+y,yc-x,15);
	putpixel(xc-y,yc+x,15);
	putpixel(xc-y,yc-x,15);
}

void main()
{
	int gd=DETECT,gm;
	int r,xk,yk,pk;
	initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
	printf("Enter Coordinates of Center of Circle: ");
	scanf("%d%d",&xc,&yc);
	printf("Enter Radius of Circle: ");
	scanf("%d",&r);
	xk=0;
	yk=r;
	symmetric(xk,yk);
	pk=1-r;
	while(xk<=yk)
	{
		if(pk<0)
		{
			xk=xk+1;
			pk=pk+2*xk+3;
		}
		else
		{
			xk=xk+1;
			yk=yk-1;
			pk=pk+2*(xk-yk)+5;
		}
		symmetric(xk,yk);
	}
	getch();
	closegraph();
}
