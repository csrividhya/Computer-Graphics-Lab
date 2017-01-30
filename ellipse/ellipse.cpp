#include<GL/glut.h>

int xc=0,yc=0;

void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_PROJECTION);
}


void draw_ellipse(int x, int y)
{
glVertex2d(xc+x,yc+y);
glVertex2d(xc-x,yc-y);
glVertex2d(xc-x,yc+y);
glVertex2d(xc+x,yc-y);
}


void ellipse()
{
int rxsq,rysq,rx=50,ry=100,x,y,px,py,p;
rxsq=rx*rx;
rysq=ry*ry;

x=0;
y=ry;
px=0;
py=2*rxsq*y;
draw_ellipse(x,y);

p=rysq+0.25*rxsq-(rxsq*ry);

while(px<py)
{
x=x+1;
px=px+(2*rysq);

if(p<0)
{
p=p+rysq+px;
}//if
else
{
y=y-1;
py=py-(2*rxsq);
p=p+rysq+px-py;
}
draw_ellipse(x,y);
}//while


p=(rysq*(x+0.5)*(x+0.5))+(rxsq*(y-1)*(y-1))-(rxsq*rysq);

while(y>0)
{
y=y-1;
py=py-(2*rxsq);

if(p>0)
	p=p+rxsq-py;
else
{
	x=x+1;
	px=px+(2*rysq);
	p=p+rxsq-py+px;
}//else

draw_ellipse(x,y);
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
ellipse();
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
