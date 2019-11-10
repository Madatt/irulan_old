//
// Created by Dawid on 23.08.2019.
//


#include <cmath>
#include "Math/Vector3.h"
#include "Math/Matrix.h"

namespace Iru {
    Vector3::Vector3() {

    }

    Vector3::Vector3(float t_x, float t_y, float t_z)
            : x(t_x), y(t_y), z(t_z) {

    }

    Vector3& Vector3::operator=(const Vector3 &t_r) {
        x = t_r.x;
        y = t_r.y;
        z = t_r.z;
        return *this;
    }

    Vector3 Vector3::operator*(const Vector3 &t_r) {
        Vector3 vec;
        vec.x = this->x * t_r.x;
        vec.y = this->y * t_r.y;
        vec.z = this->z * t_r.z;

        return vec;
    }

    Vector3& Vector3::operator*=(const Vector3 &t_r) {
        return (*this = *this * t_r);
    }

    Vector3 Vector3::operator+(const Vector3 &t_r) {
        Vector3 vec;
        vec.x = this->x + t_r.x;
        vec.y = this->y + t_r.y;
        vec.z = this->z + t_r.z;

        return vec;
    }

    Vector3& Vector3::operator+=(const Vector3 &t_r) {
        return (*this = *this + t_r);
    }

    Vector3 Vector3::operator-(const Vector3 &t_r) {
        Vector3 vec;
        vec.x = this->x - t_r.x;
        vec.y = this->y - t_r.y;
        vec.z = this->z - t_r.z;

        return vec;
    }

    Vector3& Vector3::operator-=(const Vector3 &t_r) {
        return (*this = *this - t_r);
    }

    Vector3 Vector3::normalize() {
        Vector3 vec;

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

    Vector3 Vector3::cross(Vector3 t_r) {
        Vector3 vec;

        vec.x = this->y * t_r.z - this->z * t_r.y;
        vec.y = this->z * t_r.x - this->x * t_r.z;
        vec.z = this->x * t_r.y - this->y * t_r.x;

        return vec;
    }

    Vector3 Vector3::transform(Matrix t_mat) {
        Vector3 vec;

        vec.x = x * t_mat[0] + y * t_mat[4] + z * t_mat[8] + t_mat[12];
        vec.y = x * t_mat[1] + y * t_mat[5] + z * t_mat[9] + t_mat[13];
        vec.z = x * t_mat[2] + y * t_mat[6] + z * t_mat[10] + t_mat[14];

        return vec;
    }

    float *Vector3::getPtr() {
        m_arr[0] = x;
        m_arr[1] = y;
        m_arr[2] = z;

        return m_arr;
    }

    std::ostream &operator<<(std::ostream &t_str, const Vector3 &t_vec) {
        return t_str << "[" << t_vec.x << ", " << t_vec.y << ", " << t_vec.z << "]";
    }
}
