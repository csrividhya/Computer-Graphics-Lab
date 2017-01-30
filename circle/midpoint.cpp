#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;


void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_PROJECTION);
}

void circle()
{
int xc=10,yc=50,x=0,y=50,r=50,p=1-r;
glEnable(GL_LINE_STIPPLE);
glLineStipple(1,0x00FF);
glBegin(GL_LINES);
while(x<y)
{
glVertex2d(xc+x,yc+y);
glVertex2d(xc-x,yc-y);
glVertex2d(xc+x,yc-y);
glVertex2d(xc-x,yc+y);

glVertex2d(xc+y,yc+x);
glVertex2d(xc-y,yc-x);
glVertex2d(xc+y,yc-x);
glVertex2d(xc-y,yc+x);

if(p<0)
	{
		p+=(2*x)+3;
		x++;	
		
	}

else if(p>=0)
	{
		p+=(2*(x-y))+5;
		x++;
		y--;
	}//elif
}//while
glEnd();
glFlush();
}//circle

void mydisp()
{
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5);
//x=0;y=r;
glColor3f(1,1,1);
circle();
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
