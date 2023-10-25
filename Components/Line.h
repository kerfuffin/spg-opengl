//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_LINE_H
#define DISPLAY_LINE_H

#include <GL/gl.h>
#include "../Abstracts/Drawable.h"
#include "../Window.h"

namespace graphics {

    class Line : public Drawable {
    public:
        Line(float x1, float y1, float x2, float y2);
        virtual void draw();

    private:
        float x1, y1;
        float x2, y2;
    };

    Line::Line(float x1, float y1, float x2, float y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    void Line::draw() {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex3f(x1 * Window::ASPECT_RATIO, y1, 0.0);
        glVertex3f(x2 * Window::ASPECT_RATIO, y2, 0.0);
        glEnd();
        glFlush();
    }

} // graphics

#endif //DISPLAY_LINE_H
