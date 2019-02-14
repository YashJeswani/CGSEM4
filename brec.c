#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>
//#include<math.h>
#define round(a)(int)(a+0.5)

int x1,y1,x2,y2,xmax,ymax;

void initialise()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        gluOrtho2D(-500, 500, -500, 500);
}
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
        glEnd();
        glFlush();
}

void pass()
{
    int a,b,c,d,e,f;
    glClear(GL_COLOR_BUFFER_BIT);
    xmax=glutGet(GLUT_WINDOW_WIDTH);
    ymax=glutGet(GLUT_WINDOW_HEIGHT);
    bresenham(xmax,-xmax,0,0);
    bresenham(0,0,ymax,-ymax);
    bresenham(x1,x1,y1,y2);
    bresenham(x1,x2,y2,y2);
    bresenham(x2,x2,y2,y1);
    bresenham(x2,x1,y1,y1);
    a=(x1+x2)/2;
    b=(y1+y2)/2;
    bresenham(a,x1,y1,b);
    bresenham(x1,a,b,y2);
    bresenham(a,x2,y2,b);
    bresenham(x2,a,b,y1);
    c=((3*x1)+x2)/4;
    d=((3*x2)+x1)/4;
    e=((3*y1)+y2)/4;
    f=((3*y2)+y1)/4;
    bresenham(c,d,e,e);
    bresenham(c,c,e,f);
    bresenham(c,d,f,f);
    bresenham(d,d,f,e);
    
}


int main(int argc, char** argv)
{
    printf("\nENTER x1:\n");
    scanf("%d",&x1);
    printf("\nENTER y1:\n");
    scanf("%d",&y1);
    printf("\nENTER x2:\n");
    scanf("%d",&x2);
    printf("\nENTER y2:\n");
    scanf("%d",&y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    initialise();
    glutDisplayFunc(pass);
    glutMainLoop();    
    return 0;
}                                              
