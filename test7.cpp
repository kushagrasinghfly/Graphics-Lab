#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;  

int sides;     
float radius;  

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);       
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); 

    float centerX = 250.0f; 
    float centerY = 250.0f;


    float angleStep = 2 * M_PI / sides;

    glBegin(GL_LINE_LOOP); 
    for(int i = 0; i < sides; i++) {
        float x = centerX + radius * cos(i * angleStep);
        float y = centerY + radius * sin(i * angleStep);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    cout << "Enter number of sides of the polygon: ";
    cin >> sides;
    cout << "Enter radius (size) of the polygon: ";
    cin >> radius;

    if(sides < 3) {
        cout << "Polygon must have at least 3 sides." << endl;
        return 0;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Regular Polygon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

