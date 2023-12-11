/*Write C++ program to draw a concave polygon and fill it with desired
color using scan fill algorithm. Apply the concept of inheritance. */
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
class point
{
public:
int x,y;
};
class poly
{
private:
point p[20]={200,200,200,400,400,200,400,400};
int inter[20],x,y;
int v=4,xmin,ymin,xmax,ymax;
public:
int c;
void read();
void calcs();
void display();
void ints(float);
void sort(int);
};
void poly::read()
{

p[4].x=p[0].x;
p[4].y=p[0].y;
xmin=xmax=p[0].x;
ymin=ymax=p[0].y;


}
void poly::calcs()
{
for(int i=0;i<v;i++)
{
if(xmin>p[i].x)
xmin=p[i].x;
if(xmax<p[i].x)
xmax=p[i].x;
if(ymin>p[i].y)
ymin=p[i].y;
if(ymax<p[i].y)
ymax=p[i].y;
}
}
void poly::display()
{
float s;

s=ymin+0.01;
delay(100);
cleardevice();
while(s<=ymax)
{
ints(s);
sort(s);
s++;
}

}
void poly::ints(float z)
{
int x1,x2,y1,y2,temp;
c=0;
for(int i=0;i<v;i++)
{
x1=p[i].x;
y1=p[i].y;
x2=p[i+1].x;
y2=p[i+1].y;
if(y2<y1)
{
temp=x1;
x1=x2;
x2=temp;
temp=y1;
y1=y2;
y2=temp;
}
if(z<=y2&&z>=y1)
{
if((y1-y2)==0)
x=x1;
else
{
x=((x2-x1)*(z-y1))/(y2-y1);
x=x+x1;
}
if(x<=xmax && x>=xmin)
inter[c++]=x;
}
}
}
void poly::sort(int z) // sorting
{
int temp,j,i;
for(i=0;i<v;i++)
{
line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
}
delay(100);
for(i=0; i<c;i+=2)
{
delay(100);
line(inter[i],z,inter[i+1],z);
}
}
int main() //main
{
int cl=3;
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
cleardevice();
poly x;
x.read();
x.calcs();
cleardevice();
setcolor(cl);
x.display();
closegraph(); //closing graph
getch();
return 0;
}
