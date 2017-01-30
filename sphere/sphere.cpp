#include<GL/glut.h>
#include<iostream>
using namespace std;

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
}

void drawcone()
{
glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glColor3f(0.0,0.5,0.0);
glTranslatef(0.0,0.0,-10.5);
glRotatef(45.0,0.0,1.1,0.0);
glutSolidCone(1.0,1.5,50.0,50.0);
glFlush();
}

void reshape(int x, int y)
{
if(x==0 || y==0) return;

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
glMatrixMode(GL_MODELVIEW);
glViewport(0,0,x,y);
}

int main(int argc, char ** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(500,500);
glutCreateWindow("cone");
init();
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glutDisplayFunc(drawcone);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
