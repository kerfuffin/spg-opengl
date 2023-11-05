//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_LINE_H
#define DISPLAY_LINE_H

#include <GL/gl.h>
#include "../../Abstracts/Drawable.h"
#include "../../../Window.h"
#include "../../Structures/Vec2.h"
#include "../../Structures/Color.h"

namespace graphics {

    class Line : public Drawable {
    public:
        Line(const Vec2& pos1, const Vec2& pos2, const Color& color, float width = 1.0);
        void draw() override;

        void set_pos1(const Vec2& vec2) { this->pos1 = vec2; }
        void set_pos2(const Vec2& vec2) { this->pos1 = vec2; }
        void set_color(const Color& color) { this->c = color; }
        void set_width(float _width) { this->width = _width; }

        const Vec2& get_pos1() const { return this->pos1; }
        const Vec2& get_pos2() const { return this->pos2; }
        const Color& get_color() const { return this->c; }
        float get_width() const { return this->width; }

    private:
        Vec2 pos1;
        Vec2 pos2;
        float width;
        Color c;
    };

    Line::Line(const Vec2& pos1, const Vec2& pos2, const Color& color, float width)
            : pos1(pos1), pos2(pos2), c(color), width(width) {}

    void Line::draw() {
        c.set();
        glBegin(GL_LINES);
        glLineWidth(width);
        glVertex3f(pos1.x * Window::ASPECT_RATIO, pos1.y, 0.0);
        glVertex3f(pos2.x * Window::ASPECT_RATIO, pos2.y, 0.0);
        glEnd();
        glFlush();
    }

} // graphics

#endif //DISPLAY_LINE_H
