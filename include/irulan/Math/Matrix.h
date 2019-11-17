//
// Created by Dawid on 18.08.2019.
//

#ifndef RSMOL_MATRIX_H
#define RSMOL_MATRIX_H


#include <initializer_list>
#include <string>
#include <ostream>

namespace Iru {
    class Vector3;
    class Matrix {
    public:
        Matrix();
        Matrix(const float t_att[16]);
        Matrix(const std::initializer_list<float> &t_list);

        float &operator[](int t_i);
        const float &operator[](int t_i) const;

        Matrix& operator=(const Matrix &t_r);
        Matrix operator*(const Matrix &t_r);
        Matrix& operator*=(const Matrix &t_r);
        Matrix operator+(const Matrix &t_r);
        Matrix& operator+=(const Matrix &t_r);
        Matrix operator-(const Matrix &t_r);
        Matrix& operator-=(const Matrix &t_r);

        friend std::ostream &operator<<(std::ostream &t_str, const Matrix &t_mat);

        float *getPtr();

        static Matrix getIdentity();
        static Matrix createPerspective(float t_fov, float t_asp, float t_n, float t_f);
        static Matrix createLookAt(Vector3 t_ori, Vector3 t_tar, Vector3 t_up);
        static Matrix createRotation(Vector3 t_axis, float t_angle);
        static Matrix createTranslation(Vector3 t_vec);

    private:
        float m_mat[16];

    };

    using Matrix4 = Matrix;
}

#endif