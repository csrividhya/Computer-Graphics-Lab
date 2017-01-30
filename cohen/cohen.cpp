#include<GL/glut.h>
#include<iostream>
using namespace std;
struct point
{
float x,y;
}w[4],out[20],in[20];


int nout=0;

void init()
{

glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1000,1000,-1000,1000);
}


bool inside(point p,int i)
{
	if(p.x>=w[i].x && i==0)
		return true;
	if(p.y>=w[i].y && i==1)
		return true;
	
	if(p.x<=w[i].x && i==2)
		return true;
	
	if(p.y<=w[i].y && i==3)
		return true;
return false;

}


void addvertex(point temp)
{
out[nout]=temp;
nout=nout+1;
}


point findintersect(point s, point p, int i)
{
point inter;
float m=(p.y-s.y)/(p.x-s.x);

	if(i==0 || i==2) //left right
	{
		inter.x=w[i].x;
		inter.y= s.y + m*(inter.x - s.x);

	}
	
	else if(i==1 || i==3)
	{
		inter.y=w[i].y;
		inter.x=s.x + m*(inter.y - s.y);
	}
return inter;
}

void drawpoly(point p[],int n,int tx)
{
glBegin(GL_LINE_LOOP);

for(int i=0;i<n;i++)
	glVertex2d(p[i].x+tx,p[i].y);

glEnd();
}


void clipndraw(point in[],int nin)
{
point s,p,inter;

for(int i=0;i<4;i++)
{
nout=0;
	s=in[nin-1];
	
		for(int j=0;j<nin;j++)
		{
			p=in[j];
			
				if(inside(s,i)==true && inside(p,i)==true)
					addvertex(p);

				else if(inside(s,i)==true && inside(p,i)==false)
					{
						inter=findintersect(s,p,i);
						addvertex(inter);
					}
				
				else if(inside(s,i)==false && inside(p,i)==true)
					{
					inter=findintersect(s,p,i);
					addvertex(inter);
					addvertex(p);
					}
				else
					cout<<"hello";
s=p;		}//for j
nin=nout;
					
							for(int k=0;k<nin;k++)
								in[k]=out[k];
								
										
										drawpoly(in,nin,(i+1)*350);
}//clip
}//for i



void mydisp()
{
glClear(GL_COLOR_BUFFER_BIT);


w[0].x=-800, w[0].y=-600;
w[1].x=-800, w[1].y=-800;
w[2].x=-600, w[2].y=-800;
w[3].x=-600, w[3].y=-600;


in[0].x=-900, in[0].y=-700;
in[1].x=-500, in[1].y=-700;


drawpoly(w,4,0);
drawpoly(w,4,350);
drawpoly(w,4,700);
drawpoly(w,4,1050);
drawpoly(w,4,1400);

drawpoly(in,2,0);

clipndraw(in,2);
glFlush();

}

int main(int argc, char *argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(2000,2000);
glutInitWindowPosition(100,100);
glutCreateWindow("polygon clipping");
init();
glutDisplayFunc(mydisp);
glutMainLoop();
return 0;
}
