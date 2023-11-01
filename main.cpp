#include <iostream>
#include <string>

#include <GL/freeglut.h>
#include <thread>

#include "Core.h"

using namespace std;

Core* coreGlobal;

void renderPipeline() {
    if (coreGlobal)
        coreGlobal->draw();
}

void key_up(unsigned char key, int x, int y) {
    std::cout << "key up " << key << std::endl;
    graphics::Window::key_states[key] = false;
}

void key_down(unsigned char key, int x, int y) {
    std::cout << "key down " << key << std::endl;
    graphics::Window::key_states[key] = true;
}

void init_key_states() {
    graphics::Window::key_states = new bool[256];
    for (int i = 0; i < 256; i++) {
        graphics::Window::key_states[i] = false;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    init_key_states();

    glutKeyboardFunc(key_down);
    glutKeyboardUpFunc(key_up);

    Core core;
    coreGlobal = &core;

    glutDisplayFunc(renderPipeline);
    jthread main_thread([&core]() {
        core.run();
    });
}