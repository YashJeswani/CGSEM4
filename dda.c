#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void lineDDA(float X1,float Y1,float X2,float Y2)
{

  float dx=(X2-X1);
  float dy=(Y2-Y1);
  float steps;
  float xInc,yInc,x=X1,y=Y1;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  glColor3f(1.0,0.0,0.0);
    
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
 glEnd();
  glFlush();
}
void lineDDAx(float X1,float Y1,float X2,float Y2)
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
 glEnd();
  glFlush();
}

void function()
{
       static int flag=0;
	flag++;
	 static float x1,x2,y1,y2;
	
	if(flag==1)
	{
         printf("Enter two end points of the line to be drawn:\n");
         printf("\n************************************");
         printf("\nEnter Point1( X1 , Y1):\n");
         scanf("%f%f",&x1,&y1);
          printf("\n************************************");
         printf("\nEnter Point2( X2 , Y2):\n");
         scanf("%f%f",&x2,&y2);
         return;
        }
         lineDDAx(-640,0,640,0);
	 lineDDAx(0,-480,0,480);

    lineDDA(x1,y1,x1,y2);
    lineDDA(x1,y1,x2,y1);
    lineDDA(x1,y2,x2,y2);
    lineDDA(x2,y1,x2,y2);

    lineDDA(x1,(y1+y2)/2,(x1+x2)/2,y2);
    lineDDA(x1,(y1+y2)/2,(x1+x2)/2,y1);
    lineDDA((x1+x2)/2,y2,x2,(y1+y2)/2);
    lineDDA((x1+x2)/2,y1,x2,(y1+y2)/2);

     lineDDA((3*x1 + x2)/4,(3*y2 + y1)/4,(x1 + 3*x2)/4,(3*y2 + y1)/4);	
     lineDDA((x1 + 3*x2)/4,(3*y2 + y1)/4,(x1 + 3*x2)/4,(y2 + 3*y1)/4); 
     lineDDA((x1 + 3*x2)/4,(y2 + 3*y1)/4,(3*x1 + x2)/4,(y2 + 3*y1)/4);
     lineDDA((3*x1 + x2)/4,(y2 + 3*y1)/4,(3*x1 + x2)/4,(3*y2 + y1)/4);
		
}

int main(int argc, char** argv)
{

  function();
  /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE);
  /* Set the initial window position and size */
  glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
glutCreateWindow("OpenGL - First window demo");
  /* Initialize drawing colors */
 glClearColor(1.0,1.0,1.0,0);
gluOrtho2D(-640 , 640 , -480 , 480);	
glClear(GL_COLOR_BUFFER_BIT);
  /* Call the displaying function*/    
   glutDisplayFunc(function);
  /* Keep displaying untill the program is closed */
  glutMainLoop();
  return 0;
}
