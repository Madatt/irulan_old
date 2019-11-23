//
// Created by Dawid on 23.08.2019.
//

#ifndef RSMOL_VECTOR2_H
#define RSMOL_VECTOR2_H

#include <cmath>
#include <iostream>

namespace Iru {
    class Matrix;

    template <typename T>
    class Vector2 {
    public:
        T x = 0.0f;
        T y = 0.0f;

        Vector2();
        Vector2(T t_x, T t_y);

        Vector2<T>& operator=(const Vector2<T> &t_r);
        Vector2<T> operator*(const Vector2<T> &t_r) const;
        Vector2<T>& operator*=(const Vector2<T> &t_r);
        Vector2<T> operator+(const Vector2<T> &t_r) const;
        Vector2<T>& operator+=(const Vector2<T> &t_r);
        Vector2<T> operator-(const Vector2<T> &t_r) const;
        Vector2<T>& operator-=(const Vector2<T> &t_r);

        Vector2<T> normalize() const;
        float *getPtr();

    private:
        T m_arr[2];
    };

    #include "Vector2.tpp"

    using Vector2f = Vector2<float>;
    using Vector2i = Vector2<int>;

}




#endif //RSMOL_VECTOR2_H
