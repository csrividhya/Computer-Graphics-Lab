#include<iostream>
#include<GL/glut.h>
using namespace std;

int tx=10, ty=10; 
int x=50, y=50;
int sum=0;

int transm[3][3] = { {1,0,tx},{0,1,ty},{0,0,1} }; //translation matrix 
int point[3][1] = { {x}, {y}, {1} };
int tpoint[3][1];

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void translate()
{
int i,j,k;

for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{
		sum=0;
		//for(k=0;k<3;k++)
			{
				sum += transm[i][j] * point[j][0];
				tpoint[i][0] = sum;	
			}
	}
}//outer for





}//translate

void disp()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glPointSize(5);

glBegin(GL_POINTS);
glVertex2d(x,y);
translate();
glVertex2d(tpoint[0][0],tpoint[1][0]);
//glVertex2d(-50,0);
//glVertex2d(0,0);
//glVertex2d(0,50);
glEnd();
glFlush();
}

int main(int argc, char ** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
glutInitWindowPosition(100,100);
glutInitWindowSize(500,500);
glutCreateWindow("yolo");
init();
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}
