#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int x1,y1,x2,y2,dx,dy,xinc,yinc,step,i;
	int gd,gm;
	clrscr();
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter the coordinates of the line x1,y1,x2,y2 \n");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
	{
		step=abs(dx);
		xinc=(abs(dx)/step);
		yinc=1;
	}
	else
	{
		step=abs(dy);
		yinc=(abs(dx)/step);
		xinc=1;
	}
	putpixel(x1,y1,WHITE);
	for(i=1;i<step;i++)
	{
		x1=x1+xinc;
		y1=y1+yinc;
		if(i%5==0)
			continue;
		else
			putpixel(x1,y1,WHITE);
	}
	getch();
}