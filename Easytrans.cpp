#include<iostream.h>

#include<conio.h>

#include <math.h>

#include<graphics.h>

void main()

{

int gd=DETECT,gm,ch, tx, ty, theta, sx, sy;

//initgraph(&gd,&gm, "'"");

initgraph(&gd,&gm,"c:\\Tc\\BGI");

cout<<"transformations are\n"<<"\t 1. Translation\n" <<"\t 2.Rotation 

\n"<<"\t3.Scaling";

cout<<"enter your choice"<<endl;

cin>>ch;

switch(ch)

{

case 1:

cout<<"its translation"<<endl;

rectangle (200,200, 300, 300);

cout<<"enter translation amount\n";

cin>>tx>>ty;

rectangle (200+tx, 300+ty, 400+tx,500+ty);

break;

case 2:

cout<<"its rotation"<<endl;

rectangle (200, 200, 300, 300);

cout<<"enter the angle of rotation"<<endl;

cin>>theta;

theta=(theta*3.14)/180;

rectangle (200,200, (300-200)*cos(theta)-(300-200)*sin(theta),(300-

200)*sin(theta)+(300-200) *cos(theta));

break;

case 3:

cout<<"its scaling"<<endl;

rectangle (200, 200, 300,300);

cout<<"enter scaling factors "<<endl;

cin>>sx>>sy;

rectangle (200,200, (300-200)*sx, (300-200)*sy);

break;

default:
cout<<"wrong choice"<<endl;

break;

}

getch();

closegraph();

}
