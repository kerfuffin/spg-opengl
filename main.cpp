//#include <iostream>
//#include <string>
//
//#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
//
//
//using namespace std;
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE);
//    glutInitWindowSize(300, 300);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Hello world :D");
//    glutDisplayFunc([]() {
//        glClearColor(0.0, 0.0, 0.0, 0.0);
//        glClear(GL_COLOR_BUFFER_BIT);
//        glColor3f(1.0, 1.0, 1.0);
//        glBegin(GL_POLYGON);
//        glVertex3f(0.25, 0.25, 0.0);
//        glVertex3f(0.75, 0.25, 0.0);
//        glVertex3f(0.75, 0.75, 0.0);
//        glVertex3f(0.25, 0.75, 0.0);
//        glEnd();
//        glFlush();
//    });
//    glutMainLoop();
//    return 0;
//}

#include <iostream>
#include <string>

#include <GL/freeglut.h>

#include "Core.h"

using namespace std;

Core* coreGlobal;

void renderPipeline() {
    if (coreGlobal)
        coreGlobal->draw();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    Core core;
    coreGlobal = &core;

    glutDisplayFunc(renderPipeline);
    core.run();
}