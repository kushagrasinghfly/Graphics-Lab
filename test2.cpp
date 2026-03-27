#include <GL/glut.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);

    int points[5][2] = {
	    {250, 400},
	    {350, 300},
	    {300, 150},
	    {200, 150},
	    {150, 300}
	};


    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 5; i++) {
            glVertex2iv(points[i]);
        }
    glEnd();

    glFlush();
}





int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("PENTAGON.");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
