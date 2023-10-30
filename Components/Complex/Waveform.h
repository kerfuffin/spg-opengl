//
// Created by kuose on 30.10.23.
//

#ifndef DISPLAY_WAVEFORM_H
#define DISPLAY_WAVEFORM_H

#include "../../Abstracts/Drawable.h"
#include "../Simple/Rectangle.h"

#include <utility>
#include <vector>

namespace graphics {

    class Waveform : public Drawable {
    public:
        Waveform(const std::vector<float> &waveformData, Color color, Vec2 startPosition, float size);

        void draw() override;

        void set_color(Color color) { this->c = color; }
        void set_start_position(Vec2 position) { this->startPosition = position; }
        void set_size(float s) { this->size = s; }
        void set_data(std::vector<float> d) { this->data = std::move(d); }

        Color get_color() { return this->c; }
        Vec2 get_start_position() { return this->startPosition; }
        float get_size() const { return this->size; }
        std::vector<float> get_data() { return this->data; }

    private:
        std::vector<float> data;
        Color c = Color(0, 0, 0);
        Vec2 startPosition = Vec2(0, 0);
        float size;
        std::vector<Rectangle> bars;
    };

    Waveform::Waveform(const std::vector<float> &waveformData, Color color, Vec2 startPosition, float size) {
        this->data = waveformData;
        this->c = color;
        this->startPosition = startPosition;
        this->size = size;

        // vertical bars for waves
        for (int i = 0; i < data.size(); i++) {
            float x = startPosition.x + (static_cast<float>(i) * size / 80);
            float y1 = startPosition.y;
            float y2 = startPosition.y + (data[i] * size / 100);
            bars.emplace_back(Vec2(x, y1), size / 100, y2 - y1, color);
        }
    }

    void Waveform::draw() {
        int _it = 0;
        for (auto &bar: bars) {
            bar.set_height(data[_it] * size / 100);
            bar.draw();
            _it++;
        }
    }

} // graphics

#endif //DISPLAY_WAVEFORM_H
