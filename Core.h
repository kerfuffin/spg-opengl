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
#include "Components/Simple/Text.h"
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
//    // read center pixel color
//    float pixel[3];
//    glReadPixels(480/2, 320/2, 1, 1, GL_RGB, GL_FLOAT, pixel);
//    std::cout << pixel[0] << " " << pixel[1] << " " << pixel[2] << std::endl;
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
    auto* filePicker = new FilePicker();
    add_drawable(filePicker);

    while (true) {
        update();
        draw();
        glutSwapBuffers();
        glutMainLoopEvent();
    }

    delete filePicker;
}

#endif //DISPLAY_CORE_H
