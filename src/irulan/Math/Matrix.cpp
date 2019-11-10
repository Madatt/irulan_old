//
// Created by Dawid on 18.08.2019.
//

#include <math.h>
#include <iostream>
#include <cstring>
#include "Math/Matrix.h"
#include "Math/Vector3.h"

namespace Iru {

    Matrix::Matrix()
            : m_mat{1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1} {

    }

    Matrix::Matrix(const float *t_att) : Matrix() {
        for (int i = 0; i < 16; i++)
            m_mat[i] = t_att[i];
    }

    Matrix::Matrix(const std::initializer_list<float> &t_li) : Matrix() {
        for (int i = 0; i < 16; i++)
            m_mat[i] = *(t_li.begin() + i);
    }

    float &Matrix::operator[](int t_i) {
        return m_mat[t_i];
    }

    const float &Matrix::operator[](int t_i) const {
        return m_mat[t_i];
    }


    Matrix &Matrix::operator=(const Matrix &t_r) {
        for(int i = 0; i < 16; i++)
            m_mat[i] = t_r.m_mat[i];

        return *this;
    }

    Matrix Matrix::operator*(const Matrix &t_r) {
        Matrix mat;

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                mat[y + x * 4] = 0.0;
                for (int c = 0; c < 4; c++) {
                    mat[y + x * 4] += m_mat[y + c * 4] * t_r[x * 4 + c];
                }
            }
        }

        return mat;
    }

    Matrix &Matrix::operator*=(const Matrix &t_r) {
        return (*this = *this * t_r);
    }

    Matrix Matrix::operator+(const Matrix &t_r) {
        Matrix mat;

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                mat[y + x * 4] = (*this)[y + x * 4] + t_r[y + x * 4];
            }
        }
        return mat;
    }

    Matrix &Matrix::operator+=(const Matrix &t_r) {
        return (*this = *this + t_r);
    }

    Matrix Matrix::operator-(const Matrix &t_r) {
        Matrix mat;

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                mat[y + x * 4] = (*this)[y + x * 4] - t_r[y + x * 4];
            }
        }
        return mat;
    }

    Matrix &Matrix::operator-=(const Matrix &t_r) {
        return (*this = *this - t_r);
    }

    std::ostream &operator<<(std::ostream &t_str, const Matrix &t_mat) {
        return t_str << "[" << t_mat[0] << " " << t_mat[4] << " " << t_mat[8] << " " << t_mat[12] << "\n"
                     << t_mat[1] << " " << t_mat[5] << " " << t_mat[9] << " " << t_mat[13] << "\n"
                     << t_mat[2] << " " << t_mat[6] << " " << t_mat[10] << " " << t_mat[14] << "\n"
                     << t_mat[3] << " " << t_mat[7] << " " << t_mat[11] << " " << t_mat[15] << "]";
    }


    Matrix Matrix::getIdentity() {
        return Matrix({
                              1, 0, 0, 0,
                              0, 1, 0, 0,
                              0, 0, 1, 0,
                              0, 0, 0, 1,
                      });
    }

    Matrix Matrix::createPerspective(float t_fov, float t_asp, float t_n, float t_f) {
        float dtr = M_PI / 180.0;
        float y = 1.f / tan(dtr * t_fov / 2.f);
        float x = y / t_asp;
        float nf = t_n - t_f;

        return Matrix(
                {
                        x, 0, 0, 0,
                        0, y, 0, 0,
                        0, 0, (t_f + t_n) / nf, -1,
                        0, 0, 2 * t_f * t_n / nf, 0,
                });
    }

    Matrix Matrix::createLookAt(Vector3 t_ori, Vector3 t_tar, Vector3 t_up) {
        Vector3 forw = t_ori - t_tar;
        forw = forw.normalize();

        Vector3 left = t_up.cross(forw);
        left = left.normalize();

        Vector3 up = forw.cross(left);

        Matrix mat = getIdentity();

        mat[0] = left.x;
        mat[4] = left.y;
        mat[8] = left.z;
        mat[1] = up.x;
        mat[5] = up.y;
        mat[9] = up.z;
        mat[2] = forw.x;
        mat[6] = forw.y;
        mat[10] = forw.z;

        mat[12] = -left.x * t_ori.x - left.y * t_ori.y - left.z * t_ori.z;
        mat[13] = -up.x * t_ori.x - up.y * t_ori.y - up.z * t_ori.z;
        mat[14] = -forw.x * t_ori.x - forw.y * t_ori.y - forw.z * t_ori.z;

        return mat;
    }

    Matrix Matrix::createRotation(Vector3 t_axis, float t_angle) {
        t_axis = t_axis.normalize();
        float x = t_axis.x;
        float y = t_axis.y;
        float z = t_axis.z;

        float a = M_PI / 180.f * t_angle;
        float c = cos(a);
        float s = sin(a);
        float cc = (1.f - c);

        Matrix mat = getIdentity();

        mat[0] = c + x * x * cc;
        mat[1] = x * y * cc + z * s;
        mat[2] = z * x * cc - y * s;
        mat[3] = 0.f;

        mat[4] = x * y * cc - z * s;
        mat[5] = c + y * y * cc;
        mat[6] = z * y * cc + x * s;
        mat[7] = 0.f;

        mat[8] = x * z * cc + y * s;
        mat[9] = y * z * cc - x * s;
        mat[10] = c + z * z * cc;
        mat[11] = 0.f;

        mat[12] = 0.f;
        mat[13] = 0.f;
        mat[14] = 0.f;
        mat[15] = 1.f;

        return mat;
    }

    Matrix Matrix::createTranslation(Vector3 t_vec) {
        Matrix mat;

        mat[12] = t_vec.x;
        mat[13] = t_vec.y;
        mat[14] = t_vec.z;

        return mat;
    }


    float *Matrix::getPtr() {
        return m_mat;
    }

}