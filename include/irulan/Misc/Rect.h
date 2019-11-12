//
// Created by madatt on 12.11.19.
//

#ifndef IRULAN_RECT_H
#define IRULAN_RECT_H

namespace Iru {
    class Rect {
    public:
        Rect(float t_x, float t_y, float t_w, float t_h)
                : x(t_x), y(t_y), w(t_w), h(t_h) {};

        Rect() {};

        float x = 0.f;
        float y = 0.f;
        float w = 0.f;
        float h = 0.f;
    };
}

#endif //IRULAN_RECT_H
