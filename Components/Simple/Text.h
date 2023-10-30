//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H

#include <string>
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
        void setText(const std::string& string) { this->text = string; }
    private:
        std::string text;
        Vec2 position = Vec2(0, 0);
        Color color = Color(0, 0, 0);
    };

    Text::Text(const std::string& text, const Vec2& position, const Color& color) {
        this->text = text;
        this->position = position;
        this->color = color;
    }

    void Text::draw() {
        color.set();
        glRasterPos2f(position.x, position.y);
        for (auto& c : text) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
        glFlush();
    }

} // graphics

#endif //DISPLAY_TEXT_H
