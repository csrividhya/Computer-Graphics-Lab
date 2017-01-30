#include<iostream>
#include<GL/glut.h>

using namespace std;

void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-320,320,-240,240);
}
int x=50,y=50;
int tx=10,ty=10;
int m[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
int point[3][1]={{x},{y},{1}};
int pointt[3][1]={{0},{0},{1}};
void translate()
{
int i,j;

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
pointt[i][0]+=m[i][j]*point[j][0];
}
}
}

void dtrans()
{
glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glPointSize(5);

glBegin(GL_POINTS);
glVertex2d(x,y);
translate();
glVertex2d(pointt[0][0],pointt[1][0]);
glEnd();
glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,100);
glutCreateWindow("");
init();
glutDisplayFunc(dtrans);
glutMainLoop();
return 0;
}
