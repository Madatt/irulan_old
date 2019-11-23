

#include "Math/Vector2.h"


template<typename T>
inline Vector2<T>::Vector2() {

}

template<typename T>
inline Vector2<T>::Vector2(T t_x, T t_y)
        : x(t_x), y(t_y) {

}

template<typename T>
inline Vector2<T> &Vector2<T>::operator=(const Vector2<T> &t_r) {
    x = t_r.x;
    y = t_r.y;
    return *this;
}

template<typename T>
inline Vector2<T> Vector2<T>::operator*(const Vector2<T> &t_r) const {
    Vector2 vec;
    vec.x = this->x * t_r.x;
    vec.y = this->y * t_r.y;

    return vec;
}

template<typename T>
inline Vector2<T> &Vector2<T>::operator*=(const Vector2<T> &t_r) {
    return (*this = *this * t_r);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator+(const Vector2<T> &t_r) const {
    Vector2 vec;
    vec.x = this->x + t_r.x;
    vec.y = this->y + t_r.y;

    return vec;
}

template<typename T>
inline Vector2<T> &Vector2<T>::operator+=(const Vector2<T> &t_r) {
    return (*this = *this + t_r);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-(const Vector2<T> &t_r) const {
    Vector2 vec;
    vec.x = this->x - t_r.x;
    vec.y = this->y - t_r.y;

    return vec;
}

template<typename T>
inline Vector2<T> &Vector2<T>::operator-=(const Vector2<T> &t_r) {
    return (*this = *this - t_r);
}

template<typename T>
inline Vector2<T> Vector2<T>::normalize() const {
    Vector2<T> vec;

    vec.x = x;
    vec.y = y;

    float l = std::sqrt(x * x + y * y);
    if (l == 0)
        return vec;

    vec.x = x / l;
    vec.y = y / l;

    return vec;
}



template<typename T>
inline float *Vector2<T>::getPtr() {
    m_arr[0] = x;
    m_arr[1] = y;

    return m_arr;
}

