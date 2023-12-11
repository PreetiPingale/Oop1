/*a) Write C++ program to generate snowflake using concept of fractals.
*/
#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class KochCurve
{
public:
void koch(int iteration, int x1, int y1, int x2, int y2)
{
int x3,y3,x4,y4,x5,y5,dx,dy;
if(iteration==0)
line(x1,y1,x2,y2);
else{
delay(50);
dx = (x2-x1)/3;
dy = (y2-y1)/3;
x3 = dx + x1;
y3 = dy + y1;
x4 = (int)(0.5*(x1+x2)+sqrt(3)*(y1-y2)/6);
y4 = (int)(0.5*(y1+y2)+sqrt(3)*(x2-x1)/6);
x5 = 2*dx + x1;
y5 = 2*dy + y1;
koch(iteration-1, x1,y1,x3,y3);
koch(iteration-1, x3,y3,x4,y4);
koch(iteration-1, x4,y4,x5,y5);
koch(iteration-1, x5,y5,x2,y2);
}
}
};
int main()
{
KochCurve k;
int iteration;
cout<<"\nEnter no. of iterations: ";
cin>>iteration;
int gd = DETECT, gm;
initgraph(&gd,&gm,NULL);
k.koch(iteration,150,20,20,280);
k.koch(iteration,280,280,150,20);
k.koch(iteration,20,280,280,280);
delay(3000);
closegraph();
return 0;
}
