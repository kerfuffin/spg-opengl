//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_VEC2_H
#define DISPLAY_VEC2_H

namespace graphics {
    class Vec2 {
    public:
        Vec2(float x, float y) {
            this->x = x;
            this->y = y;
        }

        float x, y;
    };
}

#endif //DISPLAY_VEC2_H
