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
        Rectangle(std::unique_ptr<Vec2> pos, float width, float height, std::unique_ptr<Color> color);

        void draw() override;

        void set_position(std::unique_ptr<Vec2> vec2) { this->pos = std::move(vec2); }

        void set_size(float width, float height) {
            this->w = width;
            this->h = height;
        }

        void set_width(float width) { this->w = width; }

        void set_height(float height) { this->h = height; }

        void set_color(const std::unique_ptr<Color>& color) { this->c = std::make_unique<Color>(color->r, color->g, color->b); }

        const std::unique_ptr<Vec2>& get_position() { return this->pos; }

        float get_width() const { return this->w; }

        float get_height() const { return this->h; }

        const std::unique_ptr<Color>& get_color() { return this->c; }

    private:
        std::unique_ptr<Vec2> pos;
        float w;
        float h;
        std::unique_ptr<Color> c;
    };

    Rectangle::Rectangle(std::unique_ptr<Vec2> pos, float width, float height, std::unique_ptr<Color> color) {
        this->pos = std::move(pos);
        this->w = width;
        this->h = height;
        this->c = std::move(color);
    }

    void Rectangle::draw() {
        c->set();
        glBegin(GL_POLYGON);
        glVertex3f(pos->x * Window::ASPECT_RATIO, pos->y, 0.0);
        glVertex3f((pos->x + w) * Window::ASPECT_RATIO, pos->y, 0.0);
        glVertex3f((pos->x + w) * Window::ASPECT_RATIO, (pos->y + h), 0.0);
        glVertex3f(pos->x * Window::ASPECT_RATIO, (pos->y + h), 0.0);
        glEnd();
        glFlush();
    }
} // graphics

#endif //DISPLAY_RECTANGLE_H
