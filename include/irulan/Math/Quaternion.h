//
// Created by Madatt on 16.09.2019.
//

#ifndef RSMOL_QUATERNION_H
#define RSMOL_QUATERNION_H

namespace Iru {
    class Matrix;
    class Vector3;

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

        Quaternion normalize();
        Quaternion conjugate();
        Matrix toMatrix();

        static Quaternion createRotation(Vector3 t_axis, float t_angle);
    };
}
#endif //RSMOL_QUATERNION_H
