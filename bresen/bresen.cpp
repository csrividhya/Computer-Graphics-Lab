//bresenham done on oct 10th

#include<GL/glut.h>
#include<math.h>

int xa=0,ya=-100,xb=-100,yb=0,p,dx,dy,xc,yc,xend;


void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_PROJECTION);
}

void bresen()
{
dx=xb-xa;
dy=yb-ya;

p=(2*abs(dy))-abs(dx);

if(xa<xb)
{
xc=xa;
yc=ya;
xend=xb;

}
else if(xb<xa)
{
xc=xb;
yc=yb;
xend=xa;
dy=-dy;
}

while(xc<=xend)
{
xc+=1;


if(p<0)
p+=(2*abs(dy));

else if(p>=0)
{
if(dy>0)
	yc+=1;
else
	yc-=1;

p+=(2*(abs(dy)-abs(dx)));
}

glVertex2d(xc,yc);
}

}

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
bresen();
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
