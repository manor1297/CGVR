#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void clip(int a[],int x,int y,float m,int xmin,int ymin,int xmax,int ymax,float *xi,float *yi)
{
  int i;

  for(i=0;i<4;i++)
    if(a[i]==1)
    {
      a[i]=0;
      break;
    }
    if(i==0 || i==1)
    {
      if(i==0)
       *yi=ymin;
      if(i==1)
	*yi=ymax;

      *xi=x+(*yi-y)/m;
    }
    if(i==2 || i==3)
    {
      if(i==3)
      *xi=xmin;
      if(i==2)
      *xi=xmax;
      *yi=y+m*(*xi-x);

    }
}
int outside(int x[],int n)
{
  int i;
  for(i=0;i<n;i++)
    if(x[i]==1)
    {
      x[i]=0;
      return 1;
    }
  return 0;
}
int checkzero(int x[],int n)
{
  int i;
  for(i=0;i<n;i++)
    if(x[i]==1)
      return 0;
  return 1;
}
int andd(int x[],int y[],int n)
{
 int i;
 for(i=0;i<n;i++)
  if(x[i]==1 && y[i]==1)
   return 1;

 return 0;
}

void main()
{
int i,x1,x2,y1,y2,xmin,xmax,ymin,ymax,gd,gm,code1[4]={0},code2[4]={0};
float m,x1i,y1i,x2i,y2i;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
printf("Enter the cordinates of line x1 y1 s2 y2\n");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
printf("Enter window boundary xmin ymin xmax ymax\n");
scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
clrscr();
m=(y2-y1)/(x2-x1);
x1i=x1;x2i=x2;y1i=y1;y2i=y2;
//line(x1,y1,x2,y2);
rectangle(xmin,ymin,xmax,ymax);
if(y1>ymax)
  code1[0]=1;
if(y1<ymin)
  code1[1]=1;
if(x1>xmax)
  code1[2]=1;
if(x1<xmin)
  code1[3]=1;
for(i=0;i<4;i++)
  printf("%d",code1[i]);
  printf("\n");
if(y2>ymax)
  code2[0]=1;
if(y2<ymin)
  code2[1]=1;
if(x2>xmax)
  code2[2]=1;
if(x2<xmin)
  code2[3]=1;
for(i=0;i<4;i++)
  printf("%d",code2[i]);
//getch();
if(checkzero(code1,4)==1 && checkzero(code2,4)==1)
  line(x1,y1,x2,y2);
//getch();
else if(andd(code1,code2,4)==1)
  printf("completely out\n");
else
{ while(checkzero(code1,4)!=1)
  {
    clip(code1,x1,y1,m,xmin,ymin,xmax,ymax,&x1i,&y1i);
  }
  while(checkzero(code2,4)!=1)
    clip(code2,x2,y2,m,xmin,ymin,xmax,ymax,&x2i,&y2i);
//  clrscr();
  getch();
 line(x1i,y1i,x2i,y2i);
}
getch();

}

