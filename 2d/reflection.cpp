//shearing 

#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

int refx=1,refy=1;

void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_PROJECTION);
}

void drawpoint(int xold, int yold, int shx, int shy,int tx, int ty)
{
int xtemp,ytemp;



glVertex2d(xtemp+tx,xtemp+ty);
}


void circle(int shx,int shy,int tx,int ty)
{
int xc=0,yc=0,x=0,y=50,r=50,p=1-r;
/*glEnable(GL_LINE_STIPPLE);
glLineStipple(1,0x00FF);*/


while(x<y)
{

glVertex2d(refx*(shx*(yc+y)+(xc+x)+tx),refy*(shy*(xc+x)+(yc+y)+ty)); 
glVertex2d(refx*(shx*(yc-y)+(xc-x)+tx),refy*(shy*(xc-x)+(yc-y)+ty));
glVertex2d(refx*(shx*(yc-y)+(xc+x)+tx),refy*(shy*(xc+x)+(yc-y)+ty));
glVertex2d(refx*(shx*(yc+y)+(xc-x)+tx),refy*(shy*(xc-x)+(yc+y)+ty));

glVertex2d(refx*(shx*(yc+x)+(xc+y)+tx),refy*(shy*(xc+y)+(yc+x)+ty)); 
glVertex2d(refx*(shx*(yc-x)+(xc-y)+tx),refy*(shy*(xc-y)+(yc-x)+ty));
glVertex2d(refx*(shx*(yc-x)+(xc+y)+tx),refy*(shy*(xc+y)+(yc-x)+ty));
glVertex2d(refx*(shx*(yc+x)+(xc-y)+tx),refy*(shy*(xc-y)+(yc+x)+ty));


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

}//circle

void mydisp()
{
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5);
//x=0;y=r;
glColor3f(1,1,1);
glBegin(GL_POINTS);
circle(0,0,0,0);
circle(2,2,-100,-100);
refx=-1;
refy=1;
circle(2,2,0,0);
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
