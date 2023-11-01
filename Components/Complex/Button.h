//
// Created by kuose on 31.10.23.
//

#ifndef DISPLAY_BUTTON_H
#define DISPLAY_BUTTON_H

#include <functional>
#include <utility>
#include <GL/gl.h>
#include "../../Abstracts/Drawable.h"
#include "../../Structures/Color.h"
#include "../../Structures/Vec2.h"
#include "../Simple/Text.h"
#include "../Simple/Rectangle.h"
#include "../../Window.h"

namespace graphics {

    class Button : public Drawable {
    public:
        Button(Vec2 pos, float width, float height, Color color, Text text, std::function<void()> callback);
        void draw() override;

        void set_focused(bool focused);
    private:
        Rectangle rectangle = Rectangle(Vec2(0, 0), 0, 0, Color(0, 0, 0));
        Text text = Text("", Vec2(0, 0), Color(0, 0, 0));
        std::function<void()> callback;
        Color color = Color(0, 0, 0);
        bool is_focused = true;
    };

    Button::Button(Vec2 pos, float width, float height, Color color, Text text, std::function<void()> callback) {
        this->rectangle = Rectangle(pos, width, height, color);
        this->text = std::move(text);
        this->text.center_in(pos, Vec2(pos.x + width, pos.y + height));
        this->callback = std::move(callback);
        this->color = color;
    }

    void Button::set_focused(bool focused) {
        this->is_focused = focused;
    }

    void Button::draw() {
        if (is_focused) {
            rectangle.set_color(Color(0.4, 0.4, 0.5));
            if (Window::key_states[13]) {
                callback();
            }
        } else {
            rectangle.set_color(color);
        }
        rectangle.draw();
        text.draw();
    }

} // graphics

#endif //DISPLAY_BUTTON_H
