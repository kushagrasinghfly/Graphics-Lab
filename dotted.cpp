#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int xStart, yStart, xEnd, yEnd;

void init()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}


void BresenhamLine(int x0, int y0, int x1, int y1)
{
    bool steep = abs(y1 - y0) > abs(x1 - x0);


    if (steep) {
        swap(x0, y0);
        swap(x1, y1);
    }

    if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = abs(y1 - y0);

    int p = 2 * dy - dx;
    int y = y0;

    int yStep = (y0 < y1) ? 5 : -5;

    glBegin(GL_POINTS);
    for (int x = x0; x <= x1; x+=5) {
        if (steep)
            glVertex2i(y, x);   
        else
            glVertex2i(x, y);

        if (p >= 0) {
            y += yStep;
            p += 2 * (dy - dx);
        } else {
            p += 2 * dy;
        }
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glPointSize(2.0);

    BresenhamLine(xStart, yStart, xEnd, yEnd);

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter x0 y0 and x1 y1: \n";
    cin >> xStart >> yStart >> xEnd >> yEnd;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

