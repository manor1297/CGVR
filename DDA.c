#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main(){
		clrscr();
		int n;
		int j=0;
		float x1,y1,x2,y2,dx,dy,steps,xi,yi;
		int gd=DETECT, gm;
		initgraph(&gd,&gm,"c:\\turboc3\\BGI");
		printf("enter 1:simple line\n2:dotted line\n3:Dashed line\n4:Thick line\n ");scanf("%d",&n);printf("enter the coordinates of starting point\n");
		scanf("%f%f",&x1,&y1);
		printf("enter the coordinates of ending point\n");
		scanf("%f%f",&x2,&y2);
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>abs(dy)){steps=abs(dx);}
		else{steps=abs(dy);}
		xi=dx/steps;
		yi=dy/steps;
		putpixel(x1,y1,WHITE);
		switch(n){
			case 1:for(int i=1;i<steps;i++){
			x1=x1+xi;
			y1=y1+yi;
			putpixel(x1,y1,WHITE);}
			break;
			case 2: for( i=1;i<steps;i++){
				 x1=x1+(3*xi);
				 y1=y1+(3*yi);
				 putpixel(x1,y1,WHITE);}
				break;
			case 3: for(i=1;i<steps;i++){
				x1=x1+xi;
				y1=y1+yi;
				putpixel(x1,y1,WHITE);
				j++;
				if(j%3==0){
					x1=x1+(3*xi);
					y1=y1+(3*yi);}}
				break;
			case 4:for(i=1;i<steps;i++){
				  x1=x1+xi;
				  y1=y1+yi;
				  putpixel(x1,y1,WHITE);
				  putpixel(x1+1,y1,WHITE);
				  putpixel(x1-1,y1,WHITE);
				  putpixel(x1,y1+1,WHITE);
				  putpixel(x1,y1-1,WHITE);
				  putpixel(x1-1,y1+1,WHITE);
				  putpixel(x1-1,y1-1,WHITE);
				  putpixel(x1+1,y1+1,WHITE);
				  putpixel(x1+1,y1-1,WHITE);}
				break;
			default: printf("invalid input");}
		getch();}
