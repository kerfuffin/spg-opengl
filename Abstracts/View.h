//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_VIEW_H
#define DISPLAY_VIEW_H

#include <GL/gl.h>
#include "../Abstracts/Drawable.h"

namespace graphics {

    class View : public Drawable {
    public:
        View() = default;
        virtual void update() = 0;
    };

} // graphics

#endif //DISPLAY_VIEW_H
