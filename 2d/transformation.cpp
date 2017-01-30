//translation, rotation, scaling

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



void bresen(int sx,int sy,int thetha,int tx,int ty, int xa, int ya, int xb, int yb)
{

//thetha*=3.14;
//thetha/=180;


int dx,dy,xend,xc,yc,p;
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
if(dx!=0)
{
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

glVertex2d(sx*(xc*cos(thetha*3.14/180)-yc*sin(thetha*3.14/180))+tx,sy*(xc*sin(thetha*3.14/180)+yc*cos(thetha*3.14/180))+ty);
}
}

else
{yc=ya;
while(yc<yb)
{
//glVertex2d(xa+tx,yc+ty);
glVertex2d(sx*(xa*cos(thetha*3.14/180)-yc*sin(thetha*3.14/180))+tx,sy*(xa*sin(thetha*3.14/180)+yc*cos(thetha*3.14/180))+ty);
yc++;
}
}
}
void circle(int sx,int sy,int tx,int ty)
{
int xc=0,yc=0,x=0,y=50,r=50,p=1-r;
/*glEnable(GL_LINE_STIPPLE);
glLineStipple(1,0x00FF);*/


while(x<y)
{

glVertex2d(sx*(xc+x)+tx,sy*(yc+y)+ty);
glVertex2d(sx*(xc-x)+tx,sy*(yc-y)+ty);
glVertex2d(sx*(xc+x)+tx,sy*(yc-y)+ty);
glVertex2d(sx*(xc-x)+tx,sy*(yc+y)+ty);

glVertex2d(sx*(xc+y)+tx,sy*(yc+x)+ty);
glVertex2d(sx*(xc-y)+tx,sy*(yc-x)+ty);
glVertex2d(sx*(xc+y)+tx,sy*(yc-x)+ty);
glVertex2d(sx*(xc-y)+tx,sy*(yc+x)+ty);

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
circle(1,1,0,0);
bresen(1,1,0,0,0,-50,0,50,0);
bresen(1,1,0,0,0,0,-50,0,50);
circle(2,2,100,100);
bresen(2,2,45,100,100,-50,0,50,0);
bresen(2,2,45,100,100,0,-50,0,50);
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
