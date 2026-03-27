#include <GL/glut.h>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std; 

int xc = 0, yc = 0;   
int a = 100;   
int b = 60;

void plotPoints(int x, int y)
{
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
}

void midpointEllipse()
{
    int x = 0;
    int y = b;

    int dx = 2 * b * b * x;
    int dy = 2 * a * a * y;

    float d1 = (b*b) - (a*a*b) + (0.25*a*a);

    glBegin(GL_POINTS);

    while (dx < dy)
    {
        plotPoints(x, y);

        if (d1 < 0)
        {
            x++;
            dx += 2 * b * b;
            d1 += dx + b*b;
        }
        else
        {
            x++;
            y--;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d1 += dx - dy + b*b;
        }
    }

    float d2 = (b*b*(x + 0.5)*(x + 0.5)) +
               (a*a*(y - 1)*(y - 1)) -
               (a*a*b*b);

    while (y >= 0)
    {
        plotPoints(x, y);

        if (d2 > 0)
        {
            y--;
            dy -= 2 * a * a;
            d2 += a*a - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d2 += dx - dy + a*a;
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2);  

    midpointEllipse();

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();   
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Ellipse Algorithm");

    cout<<"Enter The Co-ordinates of Center : \n";
    cin>>xc>>yc;

    cout<<"Enter Semi-Major Axis (a) : \n";
    cin>>a;

    cout<<"Enter Semi-Minor Axis (b) : \n";
    cin>>b;

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

