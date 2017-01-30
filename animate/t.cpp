#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

double tx,ty;

void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-250,250,-250,250);
}

void circle(int tx,int ty)
{
int xc=10,yc=50,x=0,y=50,r=50,p=1-r;
//glEnable(GL_LINE_STIPPLE);
//glLineStipple(1,0x00FF);
glBegin(GL_POINTS);


xc+=tx;
yc+=ty;

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
circle(0,0);
}

void animate1()
{
while(tx<=200)
	{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);

		tx+=0.1;
		ty+=0.1;
		circle(tx,ty);
	}

}


void animate2()
{
while(tx>=0)
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);

tx-=0.1;
ty-=0.1;
circle(tx,ty);
}

}


 void animate()
{
if(tx<=20)
	animate1();
else
	animate2();
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
glutIdleFunc(animate);
glutMainLoop();
return 0;
}
