#include <GL/glut.h>
#include <cmath>
using namespace std;

// Bresenham line algorithm
void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx)  { err += dx; y1 += sy; }
    }
    glEnd();
}


void drawHELLO() {

    
    bresenham(50, 300, 50, 350);
    bresenham(70, 300, 70, 350);
    bresenham(50, 325, 70, 325);

    
    bresenham(90, 300, 90, 350);
    bresenham(90, 350, 120, 350);
    bresenham(90, 325, 115, 325);
    bresenham(90, 300, 120, 300);

    
    bresenham(140, 300, 140, 350);
    bresenham(140, 300, 170, 300);

    
    bresenham(190, 300, 190, 350);
    bresenham(190, 300, 220, 300);

    
    bresenham(240, 300, 240, 350);
    bresenham(240, 350, 270, 350);
    bresenham(270, 350, 270, 300);
    bresenham(270, 300, 240, 300);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glPointSize(2);

    drawHELLO();

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("HELLO using Bresenham");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

