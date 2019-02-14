
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
int sign(int x)
{
        if(x>0)
                return 1;
        else if(x==0)
                return 0;
        return -1;
}
void bresenham(int x1,int x2,int y1,int y2)
{
        int s1,ex,s2,x,y,k=1;
        int dx,dy,p,temp;
        dx=abs(x2-x1);
        dy=abs(y2-y1);
        x=x1;
        y=y1;
        s1=sign(x2-x1);
        s2=sign(y2-y1);
        if(dy>dx)
        {
                temp=dx;
                dx=dy;
                dy=temp;
                ex=1;
        }
        else
                ex=0;
        p=2*dy-dx;
        while(k<=dx)
        {
                setpixel(x,y);
                if(p>=0)
                {
                        if(ex==1)
                                x=x+s1;
                        else
                                y=y+s2;
                        p=p-2*dx;
                }
                if(ex==1)
                        y=y+s2;
                else
                        x=x+s1;
                p=p+2*dy;
                k++;
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
    bresenham(xmax,-xmax,0,0);
    bresenham(0,0,ymax,-ymax);
    circleMP();
    bresenham(xc-a,xc,yc-b,yc+r);
    bresenham(xc,xc+a,yc+r,yc-b);
    bresenham(xc+a,xc-a,yc-b,yc-b);
    circleMPI();
}
void Init()
{
	/* Set clear color to white */
	glClearColor(1.0,1.0,1.0,0);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/* Set fill color to black */
 	glColor3f(0.0,0.0,0.0);
 	
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

