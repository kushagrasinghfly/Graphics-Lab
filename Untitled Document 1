#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); // 2D projection
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Yellow color for lines

    // Draw house body (square)
    glBegin(GL_LINES);
        glVertex2i(150, 150); glVertex2i(350, 150); // bottom
        glVertex2i(350, 150); glVertex2i(350, 350); // right
        glVertex2i(350, 350); glVertex2i(150, 350); // top
        glVertex2i(150, 350); glVertex2i(150, 150); // left
    glEnd();

    // Draw roof (triangle)
    glBegin(GL_LINES);
        glVertex2i(150, 350); glVertex2i(250, 450); // left roof slope
        glVertex2i(250, 450); glVertex2i(350, 350); // right roof slope
        glVertex2i(150, 350); glVertex2i(350, 350); // base of roof
    glEnd();

    // Draw door (rectangle)
    glBegin(GL_LINES);
        glVertex2i(220, 150); glVertex2i(220, 250); // left
        glVertex2i(280, 150); glVertex2i(280, 250); // right
        glVertex2i(220, 250); glVertex2i(280, 250); // top
        glVertex2i(220, 150); glVertex2i(280, 150); // bottom (optional)
    glEnd();

    // Draw left window (rectangle)
    glBegin(GL_LINES);
        glVertex2i(170, 270); glVertex2i(210, 310); // top
        glVertex2i(170, 270); glVertex2i(170, 310); // left
        glVertex2i(210, 270); glVertex2i(210, 310); // right
        glVertex2i(170, 310); glVertex2i(210, 310); // bottom
    glEnd();

    // Draw right window (rectangle)
    glBegin(GL_LINES);
        glVertex2i(290, 270); glVertex2i(330, 310); // top
        glVertex2i(290, 270); glVertex2i(290, 310); // left
        glVertex2i(330, 270); glVertex2i(330, 310); // right
        glVertex2i(290, 310); glVertex2i(330, 310); // bottom
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple House Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

