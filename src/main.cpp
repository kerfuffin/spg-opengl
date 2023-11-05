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

void key_up(unsigned char key) {
    graphics::Window::key_states[key] = false;
}

void key_down(unsigned char key) {
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

    Core* core = new Core();
    coreGlobal = core;

    glutDisplayFunc(renderPipeline);
    jthread main_thread([=]() {
        core->run();
    });
    main_thread.detach();
}

namespace py = pybind11;

PYBIND11_MODULE(display, m) {
    m.doc() = R"pbdoc(
        display library for spg project
    )pbdoc";

    m.def("start_draw_thread", &start_draw_thread, R"pbdoc(
        start drawing thread
    )pbdoc");

    m.def("print", [](const std::string& str){
        printf("%s", str.c_str());
    }, R"pbdoc(
        print string from cpp
    )pbdoc");

    m.def("handle_key_up", &key_up, R"pbdoc(
        handle key up
    )pbdoc");

    m.def("handle_key_down", &key_down, R"pbdoc(
        handle key down
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}