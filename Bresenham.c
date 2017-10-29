#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void normal(int p,int dx,int dy,int x1,int y1){
	int k;
	for(k=0;k<dx;k++){
		if(p<0){
			putpixel(x1,y1,WHITE);
			p=p+2*dy;}
		else{
			putpixel(x1,y1,WHITE);
			p=p+2*dy-2*dx;
			y1++;}
		x1++;}}
void dash(int p,int dx,int dy,int x1,int y1){
	int k;int c=0;
	for(k=0;k<dx;k++){
		if(p<0){
			putpixel(x1,y1,WHITE);
			p=p+2*dy;}else{
			putpixel(x1,y1,WHITE);
			p=p+2*dy-2*dx;
			y1++;}
		if(c%5==0)
			x1=x1+3;else
			x1++;c++;}}
void dot(int p,int dx,int dy,int x1,int y1){
	int k;
	for(k=0;k<dx;k++){if(p<0){
			putpixel(x1,y1,WHITE);
			p=p+2*dy;}else{
			putpixel(x1,y1,WHITE);
			p=p+2*dy-2*dx;
			y1++;}
		x1=x1+3;}}
void thick(int p,int dx,int dy,int x1,int y1){
	int k;
	for(k=0;k<dx;k++){if(p<0){
			putpixel(x1,y1,WHITE);
			putpixel(x1+1,y1+1,WHITE);
			putpixel(x1-1,y1-1,WHITE);
			putpixel(x1+1,y1-1,WHITE);
			putpixel(x1-1,y1+1,WHITE);
			putpixel(x1+1,y1,WHITE);
			putpixel(x1,y1+1,WHITE);
			putpixel(x1-1,y1,WHITE);
			putpixel(x1,y1-1,WHITE);
			p=p+2*dy;}else{
			putpixel(x1,y1,WHITE);
			putpixel(x1+1,y1+1,WHITE);
			putpixel(x1-1,y1-1,WHITE);
			putpixel(x1+1,y1-1,WHITE);
			putpixel(x1-1,y1+1,WHITE);
			putpixel(x1+1,y1,WHITE);
			putpixel(x1,y1+1,WHITE);
			putpixel(x1-1,y1,WHITE);
			putpixel(x1,y1-1,WHITE);
			p=p+2*dy-2*dx;
			y1++;}x1++;}}
void main(){
	int x1,y1,x2,y2,dx,dy,p;
	int gm;
	int gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	clrscr();
	printf("Enter the coorddinates x1 y1 x2 y2");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	p=(2*dy)-dx;
	int m;
	printf("Enter the option \n 1. Normal \n 2.Dot \n 3.Dash \n 4.Thick \n 5.Exit");
	scanf("%d",&m);
	switch(m){
	case 1: normal(p,dx,dy,x1,y1);break;
	case 2: dot(p,dx,dy,x1,y1);break;
	case 3: dash(p,dx,dy,x1,y1);break;
	case 4: thick(p,dx,dy,x1,y1);break;
	case 5: break;}getch();}
