#include<GL/glut.h>

void init()
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,300,0,300);
}

int dwell(double sx,double sy)
{
double dx=sx;
double dy=sy;
int i;
double fsq=dx*dx+dy*dy;

for( i=0;i<=100&&fsq<=4;i++)
{
double tmp=dx;
dx=dx*dx-dy*dy-0.5;
dy=2.0*dy*tmp+0.5;
fsq=(dx*dx)+(dy*dy);
}//for i

return i;
}

void color(double x, double y, int n)
{


	if(n==1)
		{
			glBegin(GL_POINTS);
			glColor3f(1,1,0);
			glVertex2d(x,y);
			glEnd();
		}

	else if(n==2)
		{
			glBegin(GL_POINTS);			
			glColor3f(1,0,1);
			glVertex2d(x,y);
			glEnd();
		}

glFlush();
}



void julia()
{
glClear(GL_COLOR_BUFFER_BIT);

double max=100,hymax=300,hxmax=300,zoom=1.5,cy,cx,iteration;
int hx,hy;
for(hy=1;hy<hymax;hy++)
{
	cy=(hy-hymax/2)/(0.5*zoom*hymax);
		
		for(hx=1;hx<hxmax;hx++)
		{
		 cx=(hx-hxmax/2)/(0.5*zoom*hxmax);
			
			iteration=dwell(cx,cy);

				if(iteration<=max)
					color(hx,hy,1);
				else
					color(hx,hy,2);	

		}//for hx

	
}//for hy

}


int main(int argc, char ** argv)
{
glutInit(&argc,argv);
glutInitWindowSize(300,300);
glutInitWindowPosition(100,100);
glutCreateWindow("julia");
init();
glutDisplayFunc(julia);
glutMainLoop();
return 0;
}
