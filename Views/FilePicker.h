//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_FILEPICKER_H
#define DISPLAY_FILEPICKER_H

#include <memory>
#include <vector>
#include <cmath>
#include <functional>
#include "../Abstracts/Drawable.h"
#include "../Components/Simple/Square.h"
#include "../Structures/Color.h"
#include "../Structures/Vec2.h"
#include "../Abstracts/View.h"
#include "../Components/Complex/Waveform.h"
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
    int angle = 0;
    int angle_increment = 1;
    void print_button();
};

FilePicker::FilePicker() {
    auto button = std::make_shared<Button>(
            std::make_unique<Vec2>(0, 0),
            0.7, 0.2,
            std::make_unique<Color>(0.3, 0.3, 0.3),
            std::make_unique<Text>("Button", std::make_unique<Vec2>(0.0, 0.0), std::make_unique<Color>(1, 1, 1)),
            [this] { print_button(); }
        );
    _dw.push_back(button);
    _buttons.push_back(button);
}

void FilePicker::update() {
    angle = (angle + angle_increment) % 360;
    auto& button = _buttons.front();
    auto new_pos = std::make_unique<Vec2>(
             cos(angle * M_PI / 180),
             sin(angle * M_PI / 180)
            );

    button->set_position(std::move(new_pos));
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
