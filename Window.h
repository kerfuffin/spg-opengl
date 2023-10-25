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

        Window() {
            glutInitDisplayMode (GLUT_DOUBLE);
            glutInitWindowSize(WIDTH, HEIGHT);
            glutInitWindowPosition(100, 100);
            glutCreateWindow("display");
            std::cout << "robie gluta";
        }

        ~Window() = default;
    };

} // graphics

#endif //DISPLAY_WINDOW_H
