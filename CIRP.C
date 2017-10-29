#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void mycircle(int xc,int yc,int r)
{
	int x=0,y,d;
	y=r;
	d=1-r;
	putpixel(xc+x,yc+y,WHITE);
	while(x<=y)
	{
		if(d<0)
		{
			x++;
			putpixel(xc+x,yc+y,WHITE);
			putpixel(xc+x,yc-y,WHITE);
			putpixel(xc-x,yc+y,WHITE);
			putpixel(xc-x,yc-y,WHITE);
			putpixel(xc+y,yc+x,WHITE);
			putpixel(xc+y,yc-x,WHITE);
			putpixel(xc-y,yc+x,WHITE);
			putpixel(xc-y,yc-x,WHITE);
			d=d+2*x+3;
		}
		else
		{
			x++;y--;
			putpixel(xc+x,yc+y,WHITE);
			putpixel(xc+x,yc-y,WHITE);
			putpixel(xc-x,yc+y,WHITE);
			putpixel(xc-x,yc-y,WHITE);
			putpixel(xc+y,yc+x,WHITE);
			putpixel(xc+y,yc-x,WHITE);
			putpixel(xc-y,yc+x,WHITE);
			putpixel(xc-y,yc-x,WHITE);
			d=d+2*x-2*y+5;
		}
	}
}
void main()
{
	int gd,gm;
	int r,x,y;
	clrscr();
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	printf("Enter the center(x,y) and radius \n");
	scanf("%d%d%d",&x,&y,&r);
	mycircle(x,y,r);
	getch();
}