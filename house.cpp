#include <GL/glut.h>
#include <cmath>

// ----------- Draw Sun -----------
void drawCircle(float cx, float cy, float r)
{
    glColor3f(1.0, 1.0, 0.0); // yellow sun
    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// ----------- Draw Bird -----------
void drawBird(float x, float y, float size)
{
    glColor3f(0.0, 0.0, 1.0);  // blue birds
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x - size, y + size/2);
        glVertex2f(x, y);
        glVertex2f(x + size, y + size/2);
    glEnd();
}

// ----------- Draw Ground -----------
void drawGround()
{
    glColor3f(0.0, 0.7, 0.0); // green ground
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(600, 0);
        glVertex2f(600, 120);
        glVertex2f(0, 120);
    glEnd();
}

// ----------- Draw House -----------
void drawHouse(float x, float y)
{
    // Base
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 80, y);
        glVertex2f(x + 80, y + 80);
        glVertex2f(x, y + 80);
    glEnd();

    // Roof
    glColor3f(0.9, 0.1, 0.1);
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 10, y + 80);
        glVertex2f(x + 90, y + 80);
        glVertex2f(x + 40, y + 120);
    glEnd();
}

// ----------- Draw Fence -----------
void drawFence()
{
    glColor3f(0.8, 0.6, 0.2);
    for(int i = 0; i <= 600; i += 30)
    {
        glBegin(GL_POLYGON);
            glVertex2f(i, 80);
            glVertex2f(i + 10, 80);
            glVertex2f(i + 10, 100);
            glVertex2f(i, 100);
        glEnd();
    }
    // Horizontal rail
    glBegin(GL_POLYGON);
        glVertex2f(0, 90);
        glVertex2f(600, 90);
        glVertex2f(600, 95);
        glVertex2f(0, 95);
    glEnd();
}

// ----------- Display Function -----------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.5, 1.0, 1.0); // blue sky

    // Sun
    drawCircle(500, 400, 40);

    // Birds
    drawBird(150, 350, 15);
    drawBird(200, 380, 15);
    drawBird(250, 360, 15);
    drawBird(300, 400, 15);

    // Ground
    drawGround();

    // Houses
    drawHouse(50, 120);
    drawHouse(200, 120);
    drawHouse(350, 120);

    // Fence
    drawFence();

    glFlush();
}

// ----------- Init -----------
void init()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 500);
}

// ----------- Main -----------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Simple Scene with Blue Birds");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

