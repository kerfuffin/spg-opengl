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
        Rectangle(const Vec2& pos, float width, float height, const Color& color);

        void draw() override;

        void set_position(const Vec2& vec2) { this->pos = vec2; }

        void set_size(float width, float height) {
            this->w = width;
            this->h = height;
        }

        void set_width(float width) { this->w = width; }

        void set_height(float height) { this->h = height; }

        void set_color(const Color& color) { this->c = color; }

        const Vec2& get_position() const { return this->pos; }

        float get_width() const { return this->w; }

        float get_height() const { return this->h; }

        const Color& get_color() const { return this->c; }

    private:
        Vec2 pos;
        float w;
        float h;
        Color c;
    };

    Rectangle::Rectangle(const Vec2& pos, float width, float height, const Color& color)
            : pos(pos), w(width), h(height), c(color) {}

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
