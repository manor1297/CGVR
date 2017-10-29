#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void mountain()
{
line(0,400,100,250);
line(100,250,210,400);
line(210,400,300,250);
line(300,250,420,400);
line(420,400,500,250);
line(500,250,640,400);
}

void sun(int x,int y)
{
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
circle(x,y,20);
floodfill(x,y,RED);
}

void main()
{

int x,y,i;
int gd,gm;
float t;
x=40;
y=300;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TC\\BGI");
mountain();
sun(x,y);
getch();
for(i=1;i<180;i++)
{
cleardevice();
t=(float) (i*3.14)/180;
x=(int) cos(t)-sin(t)-320*cos(t)+300*sin(t)+420;
y=(int) sin(t)+cos(t)-320*sin(t)-300*cos(t)+450;
mountain();
sun(x,y);
delay(30);
}
getch();
closegraph();
}
