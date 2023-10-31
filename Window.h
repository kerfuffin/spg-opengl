//
// Created by Kosma Gąsiorowski on 15/10/2023.
//

#ifndef DISPLAY_WINDOW_H
#define DISPLAY_WINDOW_H

#include <GL/glut.h>
#include <GL/gl.h>

namespace graphics {

    class Window {
    public:
        static constexpr int WIDTH = 480;
        static constexpr int HEIGHT = 320;
        static constexpr float ASPECT_RATIO = 320.0f / 480.0f;

        static bool* key_states;

        Window() {
            for (int i = 0; i < 256; i++) {
                key_states[i] = false;
            }

            glutInitDisplayMode (GLUT_DOUBLE);
            glutInitWindowSize(WIDTH, HEIGHT);
            glutInitWindowPosition(100, 100);
            glutCreateWindow("display");
        }

        ~Window() = default;
    };

    bool* graphics::Window::key_states = nullptr;
} // graphics

#endif //DISPLAY_WINDOW_H
