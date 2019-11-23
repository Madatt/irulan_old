//
// Created by Dawid on 18.08.2019.
//

#ifndef RSMOL_MATRIX_H
#define RSMOL_MATRIX_H


#include <initializer_list>
#include <string>
#include <ostream>
#include "Math/Vector3.h"

namespace Iru {
    class Matrix {
    public:
        Matrix();
        Matrix(const float t_att[16]);
        Matrix(const std::initializer_list<float> &t_list);

        float &operator[](int t_i);
        const float &operator[](int t_i) const;
        float get(int t_i) const{ return m_mat[t_i];};

        Matrix& operator=(const Matrix &t_r) ;
        Matrix operator*(const Matrix &t_r) const;
        Matrix& operator*=(const Matrix &t_r);
        Matrix operator+(const Matrix &t_r) const;
        Matrix& operator+=(const Matrix &t_r);
        Matrix operator-(const Matrix &t_r) const;
        Matrix& operator-=(const Matrix &t_r);
        friend std::ostream &operator<<(std::ostream &t_str, const Matrix &t_mat);

        Vector3f apply(const Vector3f &t_vec) const;

        static Matrix getIdentity();
        static Matrix createPerspective(float t_fov, float t_asp, float t_n, float t_f);
        static Matrix createOrtho(int t_w, int t_h, float t_n, float t_f);
        static Matrix createLookAt(const Vector3f &t_ori, const Vector3f &t_tar, const Vector3f &t_up);
        static Matrix createRotation(const Vector3f &t_axis, float t_angle);
        static Matrix createTranslation(const Vector3f &t_vec);
        static Matrix createScale(const Vector3f &t_vec);

        float *getPtr() ;

    private:
        float m_mat[16];

    };

    using Matrix4 = Matrix;
}

#endif