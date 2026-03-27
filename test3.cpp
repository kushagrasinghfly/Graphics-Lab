#include <GL/glut.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_LINE_STRIP);

    int low = 100;
    int high = 200;

    for (int i = 0; i <= 500; i += 25) {
        if ((i / 25) % 2 == 1)
            glVertex2i(i, low); 
        else
            glVertex2i(i, high);
    }

    glEnd();
    glFlush();
}






int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("ZIG ZAG LINE. ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
