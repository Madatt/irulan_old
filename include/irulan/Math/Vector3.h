//
// Created by Dawid on 23.08.2019.
//

#ifndef RSMOL_VECTOR3_H
#define RSMOL_VECTOR3_H

#include <iostream>

namespace Iru {
    class Matrix;

    class Vector3 {
    public:
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        Vector3();
        Vector3(float t_x, float t_y, float t_z);

        Vector3& operator=(const Vector3 &t_r);
        Vector3 operator*(const Vector3 &t_r);
        Vector3& operator*=(const Vector3 &t_r);
        Vector3 operator+(const Vector3 &t_r);
        Vector3& operator+=(const Vector3 &t_r);
        Vector3 operator-(const Vector3 &t_r);
        Vector3& operator-=(const Vector3 &t_r);

        Vector3 normalize();
        Vector3 transform(Matrix t_mat);
        Vector3 cross(Vector3 t_r);
        float *getPtr();

        friend std::ostream &operator<<(std::ostream &t_str, const Vector3 &t_vec);

    private:
        float m_arr[3];
    };
}

#endif //RSMOL_VECTOR3_H
