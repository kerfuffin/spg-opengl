//
// Created by Kosma Gąsiorowski on 15/10/2023.
//

#ifndef DISPLAY_CORE_H
#define DISPLAY_CORE_H

#include <vector>
#include <memory>
#include "Window.h"
#include "Drawable.h"


class Core {
public:
    Core();
    ~Core();

    void add_drawable(graphics::Drawable* dw);
    void draw();

private:
    graphics::Window* window;
    std::vector<std::shared_ptr<graphics::Drawable>> _dw;

};

void Core::draw() {
    for (auto& dw : _dw) {
        dw->draw();
    }
}

void Core::add_drawable(graphics::Drawable* dw) {
    _dw.push_back(static_cast<const std::shared_ptr<graphics::Drawable>>(dw));
}

Core::Core() {
    window = new graphics::Window();
}

Core::~Core() {
    delete window;
}

#endif //DISPLAY_CORE_H
