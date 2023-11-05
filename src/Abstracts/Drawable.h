//
// Created by Kosma Gąsiorowski on 16/10/2023.
//

#ifndef DISPLAY_DRAWABLE_H
#define DISPLAY_DRAWABLE_H

namespace graphics {

    class Drawable {
    public:
        Drawable() = default;
        virtual ~Drawable() = default;
        virtual void draw() = 0;
    };

} // graphics

#endif //DISPLAY_DRAWABLE_H
