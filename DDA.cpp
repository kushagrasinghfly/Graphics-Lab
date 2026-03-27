#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int x0, y0p, x1, y1p;   

int myRound(float n)
{
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}

void DDALine(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    int step = max(abs(dx), abs(dy));

    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;

    float x = x0;
    float y = y0;

    glBegin(GL_POINTS);
    for (int i = 0; i <= step; i++) {
        glVertex2i(myRound(x), myRound(y));
        x += x_incr;
        y += y_incr;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glPointSize(2);

    DDALine(x0, y0p, x1, y1p);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    cout << "Enter x0 y0: ";
    cin >> x0 >> y0p >> x1 >> y1p;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

