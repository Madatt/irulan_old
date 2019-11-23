//
// Created by Madatt on 16.09.2019.
//

#include <cmath>
#include "Math/Quaternion.h"

#include "Math/Matrix.h"

namespace Iru {

    Quaternion::Quaternion() {

    }

    Quaternion::Quaternion(float t_x, float t_y, float t_z, float t_w)
            : x(t_x), y(t_y), z(t_z), w(t_w) {

    }


    Quaternion& Quaternion::operator=(const Quaternion &t_r) {
        x = t_r.x;
        y = t_r.y;
        z = t_r.z;
        w = t_r.w;
        return *this;
    }

    Quaternion Quaternion::operator*(const Quaternion &t_r) {
        Quaternion quat;
        quat.x = (x * t_r.w) + (y * t_r.z) + (-z * t_r.y) + (w * t_r.x);
        quat.y = (-x * t_r.z) + (y * t_r.w) + (z * t_r.x) + (w * t_r.y);
        quat.z = (x * t_r.y) + (-y * t_r.x) + (z * t_r.w) + (w * t_r.z);
        quat.w = (-x * t_r.x) + (-y * t_r.y) + (-z * t_r.z) + (w * t_r.w);

        return quat;
    }

    Quaternion& Quaternion::operator*=(const Quaternion &t_r) {
        return (*this = *this * t_r);
    }

    Quaternion Quaternion::operator+(const Quaternion &t_r) {
        Quaternion quat;
        quat.x = x + t_r.x;
        quat.y = y + t_r.y;
        quat.z = z + t_r.z;
        quat.w = w + t_r.w;

        return quat;
    }

    Quaternion& Quaternion::operator+=(const Quaternion &t_r) {
        return (*this = *this + t_r);
    }

    Quaternion Quaternion::operator-(const Quaternion &t_r) {
        Quaternion quat;
        quat.x = x - t_r.x;
        quat.y = y - t_r.y;
        quat.z = z - t_r.z;
        quat.w = w - t_r.w;

        return quat;
    }

    Quaternion& Quaternion::operator-=(const Quaternion &t_r) {
        return (*this = *this - t_r);
    }

    Quaternion Quaternion::normalize() const{
        Quaternion quat;

        float n = sqrt(x * x + y * y + z * z + w * w);
        if (n == 0.f)
            n = 1.f;

        quat.x = x / n;
        quat.y = y / n;
        quat.z = z / n;
        quat.w = w / n;

        return quat;
    }

    Quaternion Quaternion::conjugate() {
        Quaternion quat;
        quat.x = -x;
        quat.y = -y;
        quat.z = -z;
        quat.w = w;

        return quat;
    }

    Matrix Quaternion::toMatrix() const{
        Matrix mat;
        Quaternion cop = this->normalize();

        float xx = cop.x * cop.x;
        float yy = cop.y * cop.y;
        float zz = cop.z * cop.z;

        mat[0] = 1 - 2 * yy - 2 * zz;
        mat[1] = 2 * cop.x * cop.y + 2 * cop.z * cop.w;
        mat[2] = 2 * cop.x * cop.z - 2 * cop.y * cop.w;

        mat[4] = 2 * cop.x * cop.y - 2 * cop.z * cop.w;
        mat[5] = 1 - 2 * xx - 2 * zz;
        mat[6] = 2 * cop.y * cop.z + 2 * cop.x * cop.w;

        mat[8] = 2 * cop.x * cop.z + 2 * cop.y * cop.w;
        mat[9] = 2 * cop.y * cop.z - 2 * cop.x * cop.w;
        mat[10] = 1 - 2 * xx - 2 * yy;

        return mat;
    }

    Quaternion Quaternion::createRotation(const Vector3f &t_axis, float t_angle) {
        Vector3f ta = t_axis.normalize();
        float a = M_PI / 180.f * t_angle;

        Quaternion quat;

        quat.x = std::sin(a / 2) * ta.x;
        quat.y = std::sin(a / 2) * ta.y;
        quat.z = std::sin(a / 2) * ta.z;
        quat.w = std::cos(a / 2);

        return quat;
    }
}