//
// Created by kuose on 31.10.23.
//

#ifndef DISPLAY_BUTTON_H
#define DISPLAY_BUTTON_H

#include <functional>
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
        Button(const Vec2& pos, float width, float height, const Color& color, const Text& text, std::function<void()> callback);
        void draw() override;

        void set_focused(bool focused);
        void set_position(const Vec2& pos);
        const Vec2& get_position();
    private:
        Rectangle rectangle;
        Text text;
        std::function<void()> callback;
        Color color;
        bool is_focused = false;
    };

    Button::Button(const Vec2& pos, float width, float height, const Color& color, const Text& text, std::function<void()> callback)
            : rectangle(pos, width, height, color), text(text), color(color), callback(std::move(callback)) {
        this->text.center_in(pos, Vec2(pos.x + width, pos.y + height));
    }

    void Button::set_focused(bool focused) {
        this->is_focused = focused;
    }

    const Vec2& Button::get_position() {
        return this->rectangle.get_position();
    }

    void Button::set_position(const Vec2& pos) {
        this->text.center_in(pos, Vec2(pos.x + this->rectangle.get_width(), pos.y + this->rectangle.get_height()));
        this->rectangle.set_position(pos);
    }

    void Button::draw() {
        if (is_focused) {
            rectangle.set_color(Color(0x42/255.f, 0x42/255.f, 0xdc/255.f));
            if (Window::key_states[13]) {
                callback();
            }
        } else {
            rectangle.set_color(Color(0x42/255.f, 0x42/255.f, 0x42/255.f));
        }
        rectangle.draw();
        text.draw();
    }

} // graphics

#endif //DISPLAY_BUTTON_H
