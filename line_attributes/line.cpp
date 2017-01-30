//attributes of line

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


void userattr() //user defined
{
glEnable(GL_LINE_STIPPLE);
glLineStipple(2,1111111100001100);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2d(0,0);
glVertex2d(-150,0);
glEnd();
}

void drawattr1() //dotted lines
{
glEnable(GL_LINE_STIPPLE);
glShadeModel(GL_SMOOTH);
glLineStipple(5,0xAAAA);
glLineWidth(5);
glBegin(GL_LINES);
glColor3f(1,0,1);
glVertex2d(0,0);
glColor3f(1,0,0);
glVertex2d(150,0);
glEnd();
}


void drawattr2() //dashed lines
{
glEnable(GL_LINE_STIPPLE);
glLineStipple(5,0x00FF);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2d(100,100);
glVertex2d(250,250);
glEnd();
}


void mydisp()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
drawattr1();
drawattr2();
userattr();
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
