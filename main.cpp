#include <iostream>
#include <string>

#include <GL/freeglut.h>
#include <thread>

#include "Core.h"
#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

using namespace std;
namespace py = pybind11;

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
    printf("key down %c", key);
    graphics::Window::key_states[key] = true;
}

void init_key_states() {
    graphics::Window::key_states = new bool[256];
    for (int i = 0; i < 256; i++) {
        graphics::Window::key_states[i] = false;
    }
}

void start_draw_thread() {
    char* argv[1];
    int argc;
    argv[0] = strdup("display");
    glutInit(&argc, argv);

    init_key_states();

    glutKeyboardFunc(key_down);
    glutKeyboardUpFunc(key_up);

    Core* core = new Core();
    coreGlobal = core;

    glutDisplayFunc(renderPipeline);
    jthread main_thread([=]() {
        core->run();
    });
}

namespace py = pybind11;

PYBIND11_MODULE(display, m) {
    m.doc() = R"pbdoc(
        display library for spg project
    )pbdoc";

    m.def("start_draw_thread", &start_draw_thread, R"pbdoc(
        start drawing thread
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}