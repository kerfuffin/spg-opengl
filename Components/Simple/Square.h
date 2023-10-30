//
// Created by Kosma Gąsiorowski on 16/10/2023.
//

#ifndef DISPLAY_SQUARE_H
#define DISPLAY_SQUARE_H

#include <GL/gl.h>
#include "../../Abstracts/Drawable.h"
#include "../../Structures/Color.h"
#include "../../Structures/Vec2.h"
#include "../../Window.h"

namespace graphics {
    class Square : public Drawable {
    public:
        Square(Vec2 pos, float size, Color color);
        void draw() override;

        void set_position(Vec2 vec2) { this->pos = vec2; }
        void set_size(float size) { this->s = size; }
        void set_color(Color color) { this->c = color; }

        Vec2 get_position() { return this->pos; }
        float get_size() const { return this->s; }
        Color get_color() { return this->c; }

    private:
        Vec2 pos = Vec2(0, 0);
        float s;
        Color c = Color(0, 0, 0);
    };

    Square::Square(Vec2 pos, float size, Color color) {
        this->pos = pos;
        this->s = size;
        this->c = color;
    }

    void Square::draw() {
        c.set();
        glBegin(GL_POLYGON);
        glVertex3f(pos.x * Window::ASPECT_RATIO, pos.y, 0.0);
        glVertex3f((pos.x+s) * Window::ASPECT_RATIO, pos.y, 0.0);
        glVertex3f((pos.x+s) * Window::ASPECT_RATIO, (pos.y+s), 0.0);
        glVertex3f(pos.x * Window::ASPECT_RATIO, (pos.y+s), 0.0);
        glEnd();
        glFlush();
    }



} // graphics

#endif //DISPLAY_SQUARE_H
