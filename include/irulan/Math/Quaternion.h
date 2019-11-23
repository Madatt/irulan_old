//
// Created by Madatt on 16.09.2019.
//

#ifndef RSMOL_QUATERNION_H
#define RSMOL_QUATERNION_H
#include "Math/Vector3.h"

namespace Iru {
    class Matrix;

    class Quaternion {
    public:
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 0.0f;

        Quaternion();
        Quaternion(float t_x, float t_y, float t_z, float t_w);

        Quaternion& operator=(const Quaternion &t_r);
        Quaternion operator*(const Quaternion &t_r);
        Quaternion& operator*=(const Quaternion &t_r);
        Quaternion operator+(const Quaternion &t_r);
        Quaternion& operator+=(const Quaternion &t_r);
        Quaternion operator-(const Quaternion &t_r);
        Quaternion& operator-=(const Quaternion &t_r);

        Quaternion normalize() const;
        Quaternion conjugate();
        Matrix toMatrix() const;

        static Quaternion createRotation(const Vector3f &t_axis, float t_angle) ;
    };
}
#endif //RSMOL_QUATERNION_H
