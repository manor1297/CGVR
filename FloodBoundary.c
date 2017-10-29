#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void boufill(int x, int y, char fcolor, char bcolor)
{
	if((getpixel(x,y)!=fcolor)&&(getpixel(x,y)!=bcolor))
		{
		putpixel(x,y,fcolor);
		boufill(x+1,y,fcolor,bcolor);
		boufill(x-1,y,fcolor,bcolor);
		boufill(x,y+1,fcolor,bcolor);
		boufill(x,y-1,fcolor,bcolor);
		boufill(x+1,y+1,fcolor,bcolor);
		boufill(x+1,y-1,fcolor,bcolor);
		boufill(x-1,y+1,fcolor,bcolor);
		boufill(x-1,y-1,fcolor,bcolor);
		}
}

void flood_fill(int x, int y, int ncolor, int ocolor)
{
    if (getpixel(x, y) == ocolor)
    {
	delay(10);
	putpixel(x, y, ncolor);
	flood_fill(x + 1, y, ncolor, ocolor);
	flood_fill(x + 1, y - 1, ncolor, ocolor);
	flood_fill(x + 1, y + 1, ncolor, ocolor);
	flood_fill(x, y - 1, ncolor, ocolor);
	flood_fill(x, y + 1, ncolor, ocolor);
	flood_fill(x - 1, y, ncolor, ocolor);
	flood_fill(x - 1, y - 1, ncolor, ocolor);
	flood_fill(x - 1, y + 1, ncolor, ocolor);
    }
}

void main()
 {
int gd, gm, x, y;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
   rectangle(250,275,300,325);
printf("Enter the SEED POINT: ");
scanf("%d %d",&x,&y);
boufill(x, y, GREEN, WHITE);
flood_fill(x,y,BLUE, GREEN);
getch();
closegraph();
 }
