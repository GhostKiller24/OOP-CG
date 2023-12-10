#include<graphics.h>
#include<math.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
//Base class
class pixel
{
public :
void plot(int x,int y)
{
 putpixel(x,y,2);
}
};
//Derive Class
class cir_algo :public pixel
{
public :
void bres_cir(int r);
};
//Bresenham’s circle algorithm
void cir_algo::bres_cir(int r)
{
int x,y,d;
x=0;
y=r;
d=3-(2*r);
do{
plot(200+x,200+y); //Eight Way symmetry of circle
plot(200+y,200+x);
plot(200+y,200-x);
plot(200+x,200-y);
plot(200-x,200-y);
plot(200-y,200-x);
plot(200-y,200+x);
plot(200-x,200+y);
if(d<=0)
{
d=d+(4*x)+6;
}
else
{
d=d+(4*(x-y))+10;
y=y-1;
}
x=x+1;
delay(50);
}
while(x<y);
}
int main()
{
cir_algo c1;
int r,gm,gd=DETECT;
cout<<"\n\t Enter the radius of circle=";
cin>>r;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
c1.bres_cir(r);
getch();
return 0;
}
