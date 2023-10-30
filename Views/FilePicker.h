//
// Created by kuose on 25.10.23.
//

#ifndef DISPLAY_FILEPICKER_H
#define DISPLAY_FILEPICKER_H

#include <memory>
#include <vector>
#include <cmath>
#include "../Abstracts/Drawable.h"
#include "../Components/Simple/Square.h"
#include "../Structures/Color.h"
#include "../Structures/Vec2.h"
#include "../Abstracts/View.h"
#include "../Components/Complex/Waveform.h"

using namespace graphics;

class FilePicker : public View {
public:
    FilePicker();
    void draw() override;
    void update();

private:
    std::vector<std::shared_ptr<Drawable>> _dw;
    Waveform* waveformL;
    Waveform* waveformR;
};

FilePicker::FilePicker() {
    waveformL = new Waveform(
            {3, 2, -3, 4, 5, -4},
            Color(1, 0, 0),
            Vec2(0, 0),
            4
            );
    _dw.push_back(std::shared_ptr<Drawable>(waveformL));
    waveformR = new Waveform(
            {-3, -2, 3, -4, -5, 4},
            Color(1, 0, 0),
            Vec2(0, 0),
            4
    );
    _dw.push_back(std::shared_ptr<Drawable>(waveformR));
}

void FilePicker::update() {
    auto dataL = waveformL->get_data();
    auto dataR = waveformR->get_data();

    // times sin of 2pi * 440Hz * time
    for (int i = 0; i < dataL.size(); i++) {
        dataL[i] = static_cast<float>(sin(2 * M_PI * 440 * dataL[i] / 441) * 5);
        dataR[i] = static_cast<float>(sin(2 * M_PI * 440 * dataL[i] / 441) * 5);
    }

    waveformL->set_data(dataL);
    waveformR->set_data(dataR);
}

void FilePicker::draw() {
    for (auto& dw : _dw) {
        dw->draw();
    }
}

#endif //DISPLAY_FILEPICKER_H
