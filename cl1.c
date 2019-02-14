
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include <math.h>

double xmax,ymax,xc,yc,r;


void setpixel(int x,int y)
{
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
}
void lineDDA(float X1,float X2,float Y1,float Y2)
{

  float dx=(X2-X1);
  float dy=(Y2-Y1);
  float steps;
  float xInc,yInc,x=X1,y=Y1;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  glColor3f(0.0,0.0,0.0);
    
  /* Plot the points */
  glBegin(GL_POINTS);
  /* Plot the first point */
  glVertex2d(x,y);
  

  int k;
  /* For every step, find an intermediate vertex */
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    glVertex2d(floor(x+0.5),floor(y+0.5));
   
  }
}

void plotPoints(int x, int y)
{
	setpixel(xc+x,yc+y);
	setpixel(xc-x,yc+y);
	setpixel(xc+x,yc-y);
	setpixel(xc-x,yc-y);
	setpixel(xc+y,yc+x);
	setpixel(xc-y,yc+x);
	setpixel(xc+y,yc-x);
	setpixel(xc-y,yc-x);
}
void circleMPI()
{
        int R=r/2;
	int x=0, y=R, p=1-R;
	plotPoints( x,y);
	while(x<y)
	{
		x=x+1;
		if(p<0)
		{
			p+=2*x+1;
		}
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		plotPoints(x,y);
	}
	glEnd();
        glFlush();
}
void circleMP()
{
	int x=0, y=r, p=1-r;
	plotPoints( x,y);
	while(x<y)
	{
		x=x+1;
		if(p<0)
		{
			p+=2*x+1;
		}
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		plotPoints(x,y);
	}
}
void pass()
{
    double a=0.866*r;
    double b=0.5*r;
    xmax=glutGet(GLUT_WINDOW_WIDTH);
    ymax=glutGet(GLUT_WINDOW_HEIGHT);
    lineDDA(xmax,-xmax,0,0);
    lineDDA(0,0,ymax,-ymax);
    circleMP();
    lineDDA(xc-a,xc,yc-b,yc+r);
    lineDDA(xc,xc+a,yc+r,yc-b);
    lineDDA(xc+a,xc-a,yc-b,yc-b);
    circleMPI();
}
void Init()
{
	/* Set clear color to white */
	glClearColor(1.0,1.0,1.0,0);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/* Set fill color to black */
 	glColor3f(1.0,0.0,0.0);
 	
	gluOrtho2D(-500, 500, -500, 500);
	
} 

int main(int argc, char **argv)
{
	printf("Enter the center of the circle :\nx=");
	scanf("%lf",&xc);
	printf("\ny=");
	scanf("%lf",&yc);
	printf("Enter the radius of the circle :");
	scanf("%lf",&r);
	
	
 	glutInit(&argc,argv);
 	
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 	/* Set the initial window position and size */
 	glutInitWindowPosition(0,0);
 	glutInitWindowSize(500,500);

	/* Create the window with title "DDA_Line" */
 	glutCreateWindow("Circle");
 
 	/* Initialize drawing colors */
 	Init();
 
 	/* Call the displaying function */
 	   glutDisplayFunc(pass);
 
 	/* Keep displaying untill the program is closed */
 	glutMainLoop();
}

