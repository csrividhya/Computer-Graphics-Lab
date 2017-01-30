#include<iostream>
using namespace std;
#include<GL/glut.h>
#include<math.h>


float height,width;
float y;
float x,x2,y2;
int dx,dy;
float steps;
float m;

void myInit()
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f) ;
glPointSize(2);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-320.0,320.0,-240.0,240.0);
}


int roundoff(float x)
{
return (int)x;
}


void fn()
{
int i;
glClear(GL_COLOR_BUFFER_BIT);
float X,Y,xincr,yincr;

glBegin(GL_POINTS);
//draw axis
for (i=-320;i<320;i++)
{
glVertex2d(i,0);
glVertex2d(0,i);
}
glEnd();


dx=x2-x;
dy=y2-y;
m=abs(dx)/abs(dy);

if(abs(dx)>abs(dy))
{
steps=dx;
}
else
{
steps=dy;
}

xincr=dx/steps;
yincr=dy/steps;

X=x+xincr;
Y=y+yincr;


glBegin(GL_POINTS);
glVertex2d(x,y);

for(i=0;i<steps;i++)
{
X+=xincr;
Y+=yincr;
glVertex2d(X,Y);
}
glEnd();
glFlush();
}

void print()
{
cout<<"HELLO WORLD \n \n ";

cout<<x<<"\n"<<y<<"\n"<<x2<<"\n"<<y2<<"\n";

dx=x2-x;
dy=y2-y;
m=dy/dx;

cout<<" slope is :"<<m<<"\n";

if(fabs(m)>1)
{
cout<<"SLOPE is GREATER THAN 1"<<"\n";
}
else if(fabs(m)<1)
{
cout<<"SLOPE is LESS THAN 1"<<"\n";
}

if(m>0)
{

if(dx>0)
cout<<"POSITIVE SLOPE. LEFT TO RIGHT "<<"\n";
else
cout<<"POSITIVE SLOPE. RIGHT TO LEFT" <<"\n";

}

if(m<0)
{

if(dx>0)
cout<<"NEGATIVE SLOPE. LEFT TO RIGHT "<<"\n";
else
cout<<"NEGATIVE SLOPE. RIGHT TO LEFT "<<"\n";

}

}

void mydisp()
{
fn();
glClear(GL_COLOR_BUFFER_BIT);

}


int main(int argc, char * argv[])
{
cout<<"Enter point1: ";
cin>>x;
cin>>y;

cout<<"Enter point2: ";
cin>>x2;
cin>>y2;

glutInit(&argc,argv) ;
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(640,480);
 glutCreateWindow("First Exercise");
 glutDisplayFunc(mydisp);
print();
 myInit();
 glutMainLoop();
 return 1;


}
