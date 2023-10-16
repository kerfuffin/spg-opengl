//
// Created by Kosma Gąsiorowski on 16/10/2023.
//

#ifndef DISPLAY_SQUARE_H
#define DISPLAY_SQUARE_H

#include <GL/gl.h>
#include "../Drawable.h"

namespace graphics {

    class Square : public graphics::Drawable {
    public:
        Square(float x, float y, float w, float h);
        virtual void draw();

    private:
        float x, y;
        float w, h;
    };

    Square::Square(float x, float y, float w, float h) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    void Square::draw() {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(x * graphics::Window::ASPECT_RATIO, y, 0.0);
        glVertex3f((x+w) * graphics::Window::ASPECT_RATIO, y, 0.0);
        glVertex3f((x+w) * graphics::Window::ASPECT_RATIO, (y+h), 0.0);
        glVertex3f(x * graphics::Window::ASPECT_RATIO, (y+h), 0.0);
        glEnd();
        glFlush();
    }

} // graphics

#endif //DISPLAY_SQUARE_H
