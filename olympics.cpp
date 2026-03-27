#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void plotPoints(int x, int y, int xc, int yc) {
    glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
    glEnd();
}

void circle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y) {
        plotPoints(x, y, xc, yc);

        if (p < 0) {
            p = p + 2 * x + 3;
        } else {
            y--;
            p = p + 2 * x - 2 * y + 5;
        }
        x++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);

    int r = 80;

    // Top row rings
    glColor3f(0.0, 0.0, 1.0);      // Blue
    circle(-200, 100, r);

    glColor3f(0.0, 0.0, 0.0);      // Black
    circle(0, 100, r);

    glColor3f(1.0, 0.0, 0.0);      // Red
    circle(200, 100, r);

    // Bottom row rings
    glColor3f(1.0, 1.0, 0.0);      // Yellow
    circle(-100, 0, r);

    glColor3f(0.0, 1.0, 0.0);      // Green
    circle(100, 0, r);

    glFlush();
}

void init() {
    glClearColor(1, 0, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Olympic Rings - Midpoint Circle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

