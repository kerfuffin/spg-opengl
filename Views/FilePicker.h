//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_FILEPICKER_H
#define DISPLAY_FILEPICKER_H

#include <memory>
#include <vector>
#include "../Abstracts/Drawable.h"
#include "../Components/Square.h"
#include "../Structures/Color.h"
#include "../Structures/Vec2.h"
#include "../Abstracts/View.h"

using namespace graphics;

class FilePicker : public View {
public:
    FilePicker();
    void draw() override;
    void update();

private:
    std::vector<std::shared_ptr<Drawable>> _dw;
};

FilePicker::FilePicker() {
    auto* square = new graphics::Square(Vec2(0, 0), 0.5, Color(1, 0, 0));
    _dw.push_back(std::shared_ptr<Drawable>(square));
}

void FilePicker::update() {
    auto* square = (Square*)_dw[0].get();
    auto color = square->get_color();
    color.g += 0.01;
    if (color.g > 1) {
        color.g = 0;
    }
    square->set_color(color);
}

void FilePicker::draw() {
    for (auto& dw : _dw) {
        dw->draw();
    }
}

#endif //DISPLAY_FILEPICKER_H
