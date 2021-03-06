//DDA done on 10th oct
#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

int xa=0,ya=100,xb=100,yb=0;
float dx,dy;
float xincr,yincr;
float m,steps;
int x=xa;
int y=ya;

void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_PROJECTION);
}

void dda()
{
dx=xb-xa;
dy=yb-ya;


if(fabs(dx)>=fabs(dy))
	steps=fabs(dx);
else
	steps=fabs(dy);

xincr=dx/steps;
yincr=dy/steps;

glVertex2d(x,y);

while(x<=steps)
{
x+=xincr;
y+=yincr;
glVertex2d(x,y);
}

}//dda


void mydisp()
{
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(3);
glBegin(GL_POINTS);
for(int i=-250;i<=250;i++)
	{
		glVertex2d(i,0);
		glVertex2d(0,i);
	}		
dda();
glEnd();
glFlush();
}


int main(int argc, char *argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("hello");
init();
glutDisplayFunc(mydisp);
glutMainLoop();
return 0;
}
