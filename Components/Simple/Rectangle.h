//
// Created by kuose on 30.10.23.
//

#ifndef DISPLAY_RECTANGLE_H
#define DISPLAY_RECTANGLE_H

#include <GL/gl.h>
#include "../../Abstracts/Drawable.h"
#include "../../Structures/Color.h"
#include "../../Structures/Vec2.h"
#include "../../Window.h"

namespace graphics {
    class Rectangle : public Drawable {
    public:
        Rectangle(Vec2 pos, float width, float height, Color color);

        void draw() override;

        void set_position(Vec2 vec2) { this->pos = vec2; }

        void set_size(float width, float height) {
            this->w = width;
            this->h = height;
        }

        void set_width(float width) { this->w = width; }

        void set_height(float height) { this->h = height; }

        void set_color(Color color) { this->c = color; }

        Vec2 get_position() { return this->pos; }

        float get_width() const { return this->w; }

        float get_height() const { return this->h; }

        Color get_color() { return this->c; }

    private:
        Vec2 pos = Vec2(0, 0);
        float w;
        float h;
        Color c = Color(0, 0, 0);
    };

    Rectangle::Rectangle(Vec2 pos, float width, float height, Color color) {
        this->pos = pos;
        this->w = width;
        this->h = height;
        this->c = color;
    }

    void Rectangle::draw() {
        c.set();
        glBegin(GL_POLYGON);
        glVertex3f(pos.x * Window::ASPECT_RATIO, pos.y, 0.0);
        glVertex3f((pos.x + w) * Window::ASPECT_RATIO, pos.y, 0.0);
        glVertex3f((pos.x + w) * Window::ASPECT_RATIO, (pos.y + h), 0.0);
        glVertex3f(pos.x * Window::ASPECT_RATIO, (pos.y + h), 0.0);
        glEnd();
        glFlush();
    }
} // graphics

#endif //DISPLAY_RECTANGLE_H
