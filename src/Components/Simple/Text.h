//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H

#include <string>
#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut_std.h>
#include "../../Abstracts/Drawable.h"
#include "../../Structures/Vec2.h"
#include "../../Structures/Color.h"

namespace graphics {

    class Text : public Drawable {
    public:
        Text(const std::string& text, const Vec2& position, const Color& color);
        void draw() override;

        void center_in(const Vec2& start, const Vec2& end);

        void setText(const std::string& string) { this->text = string; }
        void setPosition(const Vec2& vec2) { this->position = vec2; }

        int get_text_width() const { return this->text_width; }

    private:
        std::string text;
        Vec2 position;
        Color color;
        int text_width = 0;
        int text_height = glutBitmapHeight(GLUT_BITMAP_HELVETICA_18);
    };

    Text::Text(const std::string& text, const Vec2& position, const Color& color)
            : text(text), position(position), color(color) {
        for (auto& c : this->text) {
            this->text_width += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    void Text::draw() {
        color.set();
        glRasterPos2f(position.x, position.y);
        for (auto& c : text) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
        glFlush();
    }

    void Text::center_in(const Vec2& start, const Vec2& end) {
        this->position = Vec2(
                (end.x + start.x) / 1.5 / 2 - (double) this->text_width / graphics::Window::WIDTH,
                (end.y + start.y) / 2 - (double) this->text_height / graphics::Window::HEIGHT / 2.
        );
    }

} // graphics

#endif //DISPLAY_TEXT_H
