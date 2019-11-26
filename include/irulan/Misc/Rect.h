//
// Created by madatt on 12.11.19.
//

#ifndef IRULAN_RECT_H
#define IRULAN_RECT_H

namespace Iru {
    template <typename T>
    class Rect {
    public:
        Rect(T t_x, T t_y, T t_w, T t_h)
                : x(t_x), y(t_y), w(t_w), h(t_h) {};

        Rect() = default;;

        T x = 0;
        T y = 0;
        T w = 0;
        T h = 0;
    };

    using Rectf = Rect<float>;
    using Recti = Rect<int>;
}

#endif //IRULAN_RECT_H
