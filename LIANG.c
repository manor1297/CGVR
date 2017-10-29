#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
float nummax(float u1[])
{
	int i=0;
	float max=u1[i];
	for(i=0;i<4;i++)
	{
		if(u1[i]>max)
			max=u1[i];
	}
	return max;
}
float nummin(float u2[])
{
	int i=0;
	float min=u2[i];
	for(i=0;i<4;i++)
	{
		if(u2[i]<min)
			min=u2[i];
	}
	return min;
}
void main(){
	int gm,gd;
	float x1,y1,x2,y2,xmin,ymin,xmax,ymax,dx,dy,i,j=0,k=0;
	float x11,y11,x22,y22,umin,umax;
	float p1,p2,p3,p4,q1,q2,q3,q4;
	float r1,r2,r3,r4;
	float u1[4]={0.0};
	float u2[4];
	u2[0]=1.0;u2[1]=1.0;u2[2]=1.0;u2[3]=1.0;
	detectgraph(&gm,&gd);
	initgraph(&gm,&gd,"c:\\TURBOC3\\BGI");
	printf("Enter the coords of the line x1,y1,x2,y2");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	printf("Enter the window boundary xmin,ymin,xmax,ymax");
	scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
	rectangle(xmin,ymax,xmax,ymin);
	dx=x2-x1;dy=y2-y1;
	//printf("%f %f \n",dx,dy);
	p1=-dx;
	p2=dx;
	p3=-dy;
	p4=dy;
	q1=x1-xmin;
	q2=xmax-x1;
	q3=y1-ymin;
	q4=ymax-y1;
	r1=q1/p1;
	r2=q2/p2;
	r3=q3/p3;
	r4=q4/p4;
	//printf(" %f %f %f %f \n ",r1,r2,r3,r4);
	if(p1<0)
	{
		u1[k++]=r1;
	}
	else
	{
		u2[j++]=r1;
	}
	if(p2<0)
	{
		u1[k++]=r2;
	}
	else
	{
		u2[j++]=r2;
	}
	if(p3<0)
	{
		u1[k++]=r3;
	}
	else
	{
		u2[j++]=r3;
	}
	if(p4<0)
	{
		u1[k++]=r4;
	}
	else
	{
		u2[j++]=r4;
	}
       /*for(i=0;i<4;i++)
	{
		printf(" %f ",u1[i]);
	}
	for(i=0;i<4;i++)
	{
		printf(" %f ",u2[i]);
	}*/
	umax=nummax(u1);
       umin=nummin(u2);
       //printf("%f %f",umax,umin);
       x11=x1+umax*dx;
       y11=y1+umax*dy;
       x22=x1+umin*dx;
       y22=y1+umin*dy;
       line(x11,y11,x22,y22);
       //	printf("%f %f %f %f",x11,y11,x22,y22);
	getch();

}