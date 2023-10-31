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
    void update();

private:
    std::vector<std::shared_ptr<Drawable>> _dw;
    void print_button();
};

FilePicker::FilePicker() {
    Button button = Button(
            Vec2(0, 0),
            50, 20,
            Color(0.3, 0.3, 0.3),
            Text("Button", Vec2(0, 0), Color(0, 0, 0)),
            std::bind(&FilePicker::print_button, this)
            );
    _dw.push_back(std::make_shared<Button>(button));
}

void FilePicker::update() {

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
