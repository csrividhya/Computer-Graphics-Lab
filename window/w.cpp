//window to viewport

#include<GL/glut.h>

void init()
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500,500,-500,500);
}

void mydisp()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
//window
glVertex2d(-300,0);
glVertex2d(0,0);
glVertex2d(0,-300);
glVertex2d(-300,-300);

//viewport
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(100,400);
glVertex2d(400,400);
glVertex2d(400,-400);
glVertex2d(100,-400);

glEnd();


//traingle
glBegin(GL_LINE_LOOP);
glVertex2d(-250,-100);
glVertex2d(-250,-200);
glVertex2d(-150,-200);
glEnd();


int xwmin=-300, xwmax=0, ywmin=-300, ywmax=0;
int xvmin=100, xvmax=400, yvmin=-400, yvmax=400;

double sx=(xvmax-xvmin)/(xwmax-xwmin);
double sy=(yvmax-yvmin)/(ywmax-ywmin);

//xv=xvmin+sx(xw-xwmin)
//yv=yvmin+sy(xw-ywmin)

glBegin(GL_LINE_LOOP);
glVertex2d(xvmin+sx*(-250-xwmin),yvmin+sy*(-100-ywmin));
glVertex2d(xvmin+sx*(-250-xwmin),yvmin+sy*(-200-ywmin));
glVertex2d(xvmin+sx*(-150-xwmin),yvmin+sy*(-200-ywmin));
glEnd();
glFlush();


}


int main(int argc, char *argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(100,100);
glutCreateWindow("window to viewport");
init();
glutDisplayFunc(mydisp);
glutMainLoop();
return 0;
}
