//
// Created by ubuntu on 11/4/23.
//

#ifndef DISPLAY_FPSCOUNTER_H
#define DISPLAY_FPSCOUNTER_H

#include <vector>
#include <memory>
#include <chrono>
#include "../Abstracts/Drawable.h"
#include "../Components/Simple/Text.h"
#include "../Structures/Vec2.h"
#include "../Structures/Color.h"
#include "../Abstracts/View.h"

using namespace graphics;

typedef std::chrono::milliseconds _result_t;
typedef std::chrono::steady_clock _clock_t;

class FPSCounter : public View {
public:
    FPSCounter();
    void draw() override;
    void update() override;
private:
    void shift_vector();

    std::shared_ptr<Text> _avg_text;
    std::shared_ptr<Text> _low_text;
    std::chrono::time_point<_clock_t> _start;
    std::chrono::time_point<_clock_t> _end;
    size_t _elapsed[1000]{};
    float _lowest;
    float _average;
    size_t _counter;
};

FPSCounter::FPSCounter() {
    _avg_text = std::make_shared<Text>(std::string(), Vec2(0.6, 0.8), Color(1, 1, 1));
    _low_text = std::make_shared<Text>(std::string(), Vec2(0.475, 0.9), Color(1, 1, 1));

    _start = _clock_t::now();
    _lowest = 0;
    _average = 0;
    _counter = 0;

    for (int i = 0; i < 100; i++) {
        _elapsed[i] = 0;
    }
}

void FPSCounter::shift_vector() {
    for (int i = 99; i >= 0; --i)
        _elapsed[i + 1] = _elapsed[i];
}

void FPSCounter::draw() {
    _avg_text->setText("avg fps: " + std::to_string((int)round(1000.0/_average)));
    _low_text->setText("low 1% fps: " + std::to_string((int)round(1000.0/_lowest)));
    _avg_text->draw();
    _low_text->draw();
}

void FPSCounter::update() {
    _end = _clock_t::now();
    auto el = std::chrono::duration_cast<_result_t>(_end - _start).count();
    _start = _end;

    shift_vector();
    _elapsed[0] = el;


    auto avg = 0.f;
    _lowest = 0;
    for (const auto& e : _elapsed) {
        avg += (float) e;
        if ((float) e > _lowest) _lowest = (float) e;
    }
    _average = avg / (float)_counter;
    if (_counter < 100) _counter++;

}


#endif //DISPLAY_FPSCOUNTER_H
