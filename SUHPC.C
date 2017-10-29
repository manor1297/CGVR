#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void getcode(int a[], int x, int y, int w[])
{
  if(x>w[1])
       a[2] = 1;
  else a[2] = 0;
 if(x<w[0])
       a[3] = 1;
  else a[3] = 0;
 if(y<w[2])
       a[1] = 1;
  else a[1] = 0;
 if(y>w[3])
       a[0] = 1;
  else a[0] = 0;
}

void check(int a[], int b[], int xa, int ya, int xb, int yb, int w[])
{
  int i,c[4],flag=0,xc,yc,apos=-1,bpos=-1;
  float m;
  for(i=0;i<4;i++)
    if(a[i] == 0 && b[i] == 0)
	 continue;
    else flag = 1;

  if(flag == 0)
  {
    //printf("Line is completely inside the Window \n");
    line(xa,ya,xb,yb);
   // return;
  }
  else
  {
	  flag=0;
    for(i=0;i<4;i++)
	{
      c[i] = a[i] && b[i];
      if(c[i]!=0)
      flag = 1;
	}
    if(flag == 1)
    {
     // printf("Line completely outside, Hence discard Line \n");
     // return;
    }
    else
    {
      //printf("Line partially inside, partially outside \n");
      for(i=0;i<4;i++)
	  {
	if(a[i]!=0)
	  apos=i;
	if(b[i]!=0)
	  bpos=i;
	  }

      if(apos!=-1)
      {
	 // flag=0;
	  m=(float)(ya-yb)/(xa-xb);
	  if(apos==0)
	  {
	     yc=w[3];
	     xc=xa+(yc-ya)/m;
	  }
	  else if(apos==1)
	  {
	     yc=w[2];
	     xc=xa+(yc-ya)/m;
	  }
	  else if(apos==3)
	  {
	     xc=w[0];
	     yc=ya+(xc-xa)*m;
	  }
	  else if(apos==2)
	  {
	     xc=w[1];
	     yc=ya+(xc-xa)*m;
	  }
      getcode(a,xb,yb,w);
      getcode(b,xc,yc,w);
	  check(a,b,xb,yb,xc,yc,w);

      }
      else if(bpos!=-1)
      {
	  m=(float)(ya-yb)/(xa-xb);
	  if(bpos==0)
	  {
	     yc=w[3];
	     xc=xb+(yc-yb)/m;
	  }
	  else if(bpos==1)
	  {
	     yc=w[2];
	     xc=xb+(yc-yb)/m;
	  }
	  else if(bpos==3)
	  {
	     xc=w[0];
	     yc=yb+(xc-xb)*m;
	  }
	  else if(bpos==2)
	  {
	     xc=w[1];
	     yc=yb+(xc-xb)*m;
	  }
	  getcode(a,xa,ya,w);
	  getcode(b,xc,yc,w);
	  check(a,b,xa,ya,xc,yc,w);
      }
    }
  }
}

void main()
{
  int i,gm,gd,x1,x2,y1,y2,xa[10],ya[10],a[4],b[4],window[4],n;
  gd=DETECT;
  clrscr();
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  printf("Enter diagonal co-ordinates of Window : \n");
  scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

  window[0] = x1;
  window[1] = x2;
  window[2] = y1;
  window[3] = y2;

  printf("Enter number of side of polygon \n");
  scanf("%d",&n);

  printf("Enter coordinates of vertices\n");
  for(i=0;i<n;i++)
  {
	  scanf("%d %d",&xa[i],&ya[i]);

  }
xa[n]=xa[0];
ya[n]=ya[0];
printf("Before clipping\n");
 rectangle(x1,y1,x2,y2);
for(i=0;i<n;i++)
{
	line(xa[i],ya[i],xa[i+1],ya[i+1]);
}
getch();
cleardevice();
  //line(xa,ya,xb,yb);
 // getcode(a,xa,ya,window);
  //getcode(b,xb,yb,window);
 printf("After clipping\n");
 rectangle(x1,y1,x2,y2);
// setcolor(6);
  for(i=0;i<n;i++)
  {
	  getcode(a,xa[i],ya[i],window);
	  getcode(b,xa[i+1],ya[i+1],window);
	  check(a,b,xa[i],ya[i],xa[i+1],ya[i+1],window);
  }

 //setcolor(6);
  //check(a,b,xa,ya,xb,yb,window);
  getch();
}
