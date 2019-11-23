

#include "Math/Vector3.h"


template<typename T>
inline Vector3<T>::Vector3() {

}

template<typename T>
inline Vector3<T>::Vector3(T t_x, T t_y, T t_z)
        : x(t_x), y(t_y), z(t_z) {

}

template<typename T>
template<typename U>
inline Vector3<T>::Vector3(const Vector2<U> &t_v)
        : x(t_v.x), y(t_v.y), z(0) {

}
template<typename T>
inline Vector3<T> &Vector3<T>::operator=(const Vector3<T> &t_r) {
    x = t_r.x;
    y = t_r.y;
    z = t_r.z;
    return *this;
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(const Vector3<T> &t_r) const {
    Vector3 vec;
    vec.x = this->x * t_r.x;
    vec.y = this->y * t_r.y;
    vec.z = this->z * t_r.z;

    return vec;
}

template<typename T>
inline Vector3<T> &Vector3<T>::operator*=(const Vector3<T> &t_r) {
    return (*this = *this * t_r);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T> &t_r) const {
    Vector3 vec;
    vec.x = this->x + t_r.x;
    vec.y = this->y + t_r.y;
    vec.z = this->z + t_r.z;

    return vec;
}

template<typename T>
inline Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &t_r) {
    return (*this = *this + t_r);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T> &t_r) const {
    Vector3 vec;
    vec.x = this->x - t_r.x;
    vec.y = this->y - t_r.y;
    vec.z = this->z - t_r.z;

    return vec;
}

template<typename T>
inline Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &t_r) {
    return (*this = *this - t_r);
}

template<typename T>
inline Vector3<T> Vector3<T>::normalize() const {
    Vector3<T> vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;

    float l = std::sqrt(x * x + y * y + z * z);
    if (l == 0)
        return vec;

    vec.x = x / l;
    vec.y = y / l;
    vec.z = z / l;

    return vec;
}

template<typename T>
inline Vector3<T> Vector3<T>::cross(const Vector3<T> &t_r) const {
    Vector3 vec;

    vec.x = this->y * t_r.z - this->z * t_r.y;
    vec.y = this->z * t_r.x - this->x * t_r.z;
    vec.z = this->x * t_r.y - this->y * t_r.x;

    return vec;
}



template<typename T>
inline float *Vector3<T>::getPtr() {
    m_arr[0] = x;
    m_arr[1] = y;
    m_arr[2] = z;

    return m_arr;
}

