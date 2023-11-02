//
// Created by kuose on 31.10.23.
//

#ifndef DISPLAY_BUTTON_H
#define DISPLAY_BUTTON_H

#include <functional>
#include <memory>
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
        Button(std::unique_ptr<Vec2>&& pos, float width, float height, std::unique_ptr<Color> color, std::unique_ptr<Text> text, std::function<void()> callback);
        void draw() override;

        void set_focused(bool focused);
        void set_position(std::unique_ptr<Vec2> pos);
    private:
        std::unique_ptr<Rectangle> rectangle;
        std::unique_ptr<Text> text;
        std::function<void()> callback;
        std::unique_ptr<Color> color;
        bool is_focused = true;
    };

    Button::Button(std::unique_ptr<Vec2>&& pos, float width, float height, std::unique_ptr<Color> color, std::unique_ptr<Text> text, std::function<void()> callback) {
        this->text = std::move(text);
        this->text->center_in(pos, std::make_unique<Vec2>(pos->x + width, pos->y + height));
        this->callback = std::move(callback);
        this->rectangle = std::make_unique<Rectangle>(std::move(pos), width, height, std::move(color));
        this->color = std::move(color);
    }

    void Button::set_focused(bool focused) {
        this->is_focused = focused;
    }

    void Button::set_position(std::unique_ptr<Vec2> pos) {
        this->text->center_in(pos, std::make_unique<Vec2>(
                pos->x + this->rectangle->get_width(),
                pos->y + this->rectangle->get_height()
                ));
        this->rectangle->set_position(std::move(pos));
    }

    void Button::draw() {
        if (is_focused) {
            rectangle->set_color(std::make_unique<Color>(0.4, 0.4, 0.5));
            if (Window::key_states[13]) {
                callback();
            }
        } else {
            rectangle->set_color(color);
        }
        rectangle->draw();
        text->draw();
    }

} // graphics

#endif //DISPLAY_BUTTON_H
