//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_FILEPICKER_H
#define DISPLAY_FILEPICKER_H

#include <vector>
#include <cmath>
#include <functional>
#include "../Abstracts/Drawable.h"
#include "../Components/Simple/Square.h"
#include "../Structures/Color.h"
#include "../Structures/Vec2.h"
#include "../Abstracts/View.h"
#include "../Components/Complex/Button.h"

using namespace graphics;

class FilePicker : public View {
public:
    FilePicker();
    void draw() override;
    void update() override;

private:
    std::vector<std::shared_ptr<Drawable>> _dw;
    std::vector<std::shared_ptr<Button>> _buttons;
    float angle = 0;
    float angle_increment = 7.5;
    int counter = 0;
    void print_button();
    void rotate(int& ctr);
};

FilePicker::FilePicker() {
    for (int i = 0; i < 6; i++) {
        auto button = std::make_shared<Button>(
                Vec2(0, 0),
                1.5, 0.4,
                Color(0.3, 0.3, 0.3),
                Text(
                        std::string(1,'0' + i),
                        Vec2(0.0, 0.0),
                        Color(1, 1, 1)
                ),
                [this] { print_button(); }
        );
        _dw.push_back(button);
        _buttons.push_back(button);
    }
    int ctr = 1;
    rotate(ctr);
}

void FilePicker::rotate(int& ctr) {
    for (auto& button : _buttons) {
        float fake_angle = angle;

        fake_angle += angle_increment * 3 * (float)ctr;
        button->set_focused(false);
        if (fake_angle >= 60) fake_angle -= 135;
        if (fake_angle <= 7.5 && fake_angle >= -7.5) button->set_focused(true);
        Vec2 new_pos(
                -1.5 - 0.7 + cos(fake_angle * M_PI / 180),
                -0.2 + sin(fake_angle * M_PI / 180) * 1.5
        );
        button->set_position(new_pos);
        ctr += 1;
    }
}

void FilePicker::update() {
    if (graphics::Window::key_states[114] && counter % 4 == 0) {
        angle += angle_increment;
        if (angle == 60) angle = -75;
        int ctr = 1;
        rotate(ctr);
    }
    counter++;
}

void FilePicker::draw() {
    for (auto& dw : _dw) {
        dw->draw();
    }
}

void FilePicker::print_button() {
    std::cout << "Button pressed" << std::endl;
}

#endif //DISPLAY_FILEPICKER_H
