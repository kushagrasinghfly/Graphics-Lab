#include <GL/glut.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_LINES);
            glVertex2i(100,100);
            glVertex2i(400,400);
    glEnd();

    glFlush();
}





int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("a line.");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
