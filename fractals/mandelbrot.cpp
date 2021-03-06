//Mandelbrot

#include<GL/glut.h>

void init()
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,1000,0,1000);
}


void disp()
{
glClear(GL_COLOR_BUFFER_BIT);
//glPointSize(5);
glBegin(GL_POINTS);
//glVertex2d(100,100);
//manda();
double rmin=-2.25;
double rmax=0.75;
double imin=-1.5;
double imax=1.5;

double h=1000,w=1000;

double re_f=(rmax-rmin)/(w-1);
double im_f=(imax-imin)/(h-1);


int max=50;

for(int y=0;y<h;y++)
{	
	double c_im = imax - (y*im_f);
	
		for(int x=0;x<w;x++)
		{
			double c_re= rmin + (x*re_f);
			
					double z_im=c_im;
					double z_re=c_re;
					bool inside=true;

				for(int i=0;i<max;i++)
				{
					

					double z_im2=(z_im * z_im);
					double z_re2=(z_re * z_re);

						if( (z_re2 + z_im2 )>4)
						{
							inside = false;
							break;	
						}
						z_im = c_im + (2*z_re*z_im);
						z_re = c_re - z_im2 + z_re2;
					
}
							


				//for i
						if(inside)
							{
								glVertex2d(x,y);
							}

		}//for x 
}//for y

glEnd();
glFlush();
}

int main(int argc, char ** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(100,100);
glutCreateWindow("Mandelbrot");
init();
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}
