//
// Created by Dawid on 23.08.2019.
//

#ifndef RSMOL_VECTOR3_H
#define RSMOL_VECTOR3_H

#include <cmath>
#include <iostream>
#include "Math/Vector2.h"

namespace Iru {
    class Matrix;

    template <typename T>
    class Vector3 {
    public:
        T x = 0.0f;
        T y = 0.0f;
        T z = 0.0f;

        Vector3();
        Vector3(T t_x, T t_y,T t_z);
        template <typename U> Vector3(const Vector2<U> &t_v);

        Vector3<T>& operator=(const Vector3<T> &t_r);
        Vector3<T> operator*(const Vector3<T> &t_r) const;
        Vector3<T>& operator*=(const Vector3<T> &t_r);
        Vector3<T> operator+(const Vector3<T> &t_r) const;
        Vector3<T>& operator+=(const Vector3<T> &t_r);
        Vector3<T> operator-(const Vector3<T> &t_r) const;
        Vector3<T>& operator-=(const Vector3<T> &t_r);

        Vector3<T> normalize() const;
        Vector3<T> cross(const Vector3<T> &t_r) const;
        float *getPtr();

    private:
        T m_arr[3];
    };

    #include "Vector3.tpp"

    using Vector3f = Vector3<float>;
    using Vector3i = Vector3<int>;

}




#endif //RSMOL_VECTOR3_H
