//
// Created by Kosma Gąsiorowski on 15/10/2023.
//

#ifndef DISPLAY_CORE_H
#define DISPLAY_CORE_H

#include <vector>
#include <memory>
#include "Window.h"
#include "Abstracts/Drawable.h"
#include "Views/FilePicker.h"
#include "Components/Text.h"
#include <chrono>

class Core {
public:
    Core();
    ~Core();

    void add_drawable(graphics::View* dw);
    void draw();

    void update();

    [[noreturn]] void run();

private:
    graphics::Window* window;
    std::vector<std::shared_ptr<graphics::View>> _dw;
};

void Core::draw() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto& dw : _dw) {
        dw->draw();
    }
}

void Core::add_drawable(graphics::View* dw) {
    _dw.push_back(static_cast<const std::shared_ptr<graphics::View>>(dw));
}

Core::Core() {
    window = new graphics::Window();

}

Core::~Core() {
    delete window;
}

void Core::update() {
    for (auto& dw : _dw) {
        dw->update();
    }
}

[[noreturn]] void Core::run() {
    while (true) {
        update();
        draw();
        glutSwapBuffers();
        glutMainLoopEvent();
    }
}

#endif //DISPLAY_CORE_H
