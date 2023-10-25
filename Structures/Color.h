//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_COLOR_H
#define DISPLAY_COLOR_H

#include <GL/gl.h>

namespace graphics {
    class Color {
    public:
        Color(float r, float g, float b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        void set() const {
            glColor3f(r, g, b);
        }

        float r, g, b;
    };
}

#endif //DISPLAY_COLOR_H
