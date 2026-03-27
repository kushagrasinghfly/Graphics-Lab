#include <GL/glut.h>
#include <vector>


struct Point {
    float x, y;
};

std::vector<Point> points; 


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); 

    glBegin(GL_POINTS);
    for (auto &p : points) {
        glVertex2f(p.x, p.y); 
    }
    glEnd();

    glFlush();
}


void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        float oglX = (float)x;
        float oglY = (float)(windowHeight - y); 
        points.push_back({oglX, oglY});
        glutPostRedisplay();
    }
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glColor3f(1.0, 1.0, 0.0); 
    glPointSize(5.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500); 
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Click to Place Points");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse); 

    glutMainLoop();
    return 0;
}

