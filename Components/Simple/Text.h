//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H

#include <memory>
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
        Text(const std::string& text, std::unique_ptr<Vec2> position, std::unique_ptr<Color> color);
        void draw() override;

        void center_in(const std::unique_ptr<Vec2>& start, const std::unique_ptr<Vec2>& end);

        void setText(const std::string& string) { this->text = string; }
        void setPosition(std::unique_ptr<Vec2> vec2) { this->position = std::move(vec2); }

        int get_text_width() const { return this->text_width; }

    private:
        std::string text;
        std::unique_ptr<Vec2> position;
        std::unique_ptr<Color> color;
        int text_width = 0;
        int text_height = glutBitmapHeight(GLUT_BITMAP_HELVETICA_18);
    };

    Text::Text(const std::string& text, std::unique_ptr<Vec2> position, std::unique_ptr<Color> color) {
        this->text = text;
        this->position = std::move(position);
        this->color = std::move(color);
        for (auto& c : this->text) {
            this->text_width += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    void Text::draw() {
        color->set();
        glRasterPos2f(position->x, position->y);
        for (auto& c : text) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
        glFlush();
    }

    void Text::center_in(const std::unique_ptr<Vec2>& start, const std::unique_ptr<Vec2>& end) {
        auto new_pos = std::make_unique<Vec2>(
                (end->x + start->x) / 1.5 / 2 - (double) this->text_width / graphics::Window::WIDTH,
                (end->y + start->y) / 2 - (double) this->text_height / graphics::Window::HEIGHT / 2.
        );
        this->position = std::move(new_pos);
    }

} // graphics

#endif //DISPLAY_TEXT_H
