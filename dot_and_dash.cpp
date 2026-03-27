#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int x0, y0p, x1, y1p;

void bresenham(int x1, int y1, int x2, int y2) {
    bool steep = abs(y2 - y1) > abs(x2 - x1);
    bool isPrint = true;
    bool flag = true;
    int cnt = 0;
    
    if(steep) {
    	swap(x2, y2);
    	swap(x1, y1);
    }
    
    if(x1 > x2) {
    	swap(x1, x2);
    	swap(y1, y2);
    }
   
    float dx = x2 - x1;
    float dy = abs(y2 - y1);

    int steps = abs(dx);

    float x = x1;
    float y = y1;
    float p = 2*dy - dx;
    int yStep = (y1 < y2) ? 1 : -1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
    	if(isPrint) {
    		if(steep)
    			glVertex2i(round(y), round(x));
    		else
    			glVertex2i(round(x), round(y));
    	}
    		
        if(p >= 0 ) {	
        	y += yStep;
        	p = p + 2*dy - 2*dx;
        } else {
        	p = p + 2*dy;
        }
        x += 1;
        
        if(isPrint) {
        	if(flag) {
			if(cnt >= 2) {
		        flag = !flag;
			cnt = 0;
			isPrint = !isPrint;
			}
		} else {
			if(cnt >= 8) {
			flag = !flag;
			cnt = 0;
			isPrint = !isPrint;
			}
		}
	}
	if(cnt >= 3 && !isPrint) {
		isPrint = !isPrint;
	}
       	cnt++;
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glPointSize(2.0);
    
    bresenham(x0, y0p, x1, y1p);
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}


int main(int argc, char** argv) {
    cout << "Enter x1 y1 x2 y2: ";
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

