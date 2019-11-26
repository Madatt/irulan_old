//
// Created by Madatt on 19.09.2019.
//


#include <cstring>
#include <cmath>
#include <fstream>
#include <iostream>
#include "Graph/Texture2D.h"
#include "glad/glad.h"

namespace Iru {
    Texture2D::Texture2D() {
        glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
    }

    Texture2D::Texture2D(Image t_img) : Texture2D() {
        m_size.x = t_img.width;
        m_size.y = t_img.height;

        create(m_size.x, m_size.y);
        setData(0, 0, m_size.x, m_size.y, Iru::BGR, t_img.data);
    }

    Texture2D::Texture2D(int t_w, int t_h) : Texture2D() {
        create(t_w, t_h);
    }

    Texture2D::Texture2D(Texture2D &&t_tex) : Texture2D() {
        m_id = t_tex.m_id;
        m_size.x = t_tex.m_size.x;
        m_size.y = t_tex.m_size.y;

        t_tex.m_id = 0;
        t_tex.m_size.x = 0;
        t_tex.m_size.y = 0;
    }

    Texture2D::~Texture2D() {
        release();
    }

    Texture2D &Texture2D::operator=(Texture2D &&t_r) {
        if (this != &t_r) {
            release();
            m_id = t_r.m_id;
            m_size.x = t_r.m_size.x;
            m_size.y = t_r.m_size.y;

            t_r.m_id = 0;
        }
        return *this;
    }

    void Texture2D::create(int t_w, int t_h) {
        m_size.x = t_w;
        m_size.y = t_h;

        glTextureStorage2D(m_id, 1, GL_RGBA8, t_w, t_h);
        glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    void Texture2D::setData(int t_x, int t_y, int t_w, int t_h, Format t_f, void *data) {
        glTextureSubImage2D(m_id, 0, t_x, t_y, t_w, t_h, t_f, GL_UNSIGNED_BYTE, data);
    }

    Texture2D Texture2D::_loadBMP(std::string t_path) {
        std::ifstream file(t_path, std::ios::binary);
        if (!file.is_open()) {
            std::cout << "asd" << std::endl;
            return Texture2D();
        }

        char info[54];
        file.read(info, 54);

        Image img;
        int pos;

        memcpy(&img.width, info + 18, sizeof(int));
        memcpy(&img.height, info + 22, sizeof(int));
        memcpy(&pos, info + 0x0A, sizeof(int));

        file.seekg(pos, file.beg);

        int off = std::ceil(24.0 * (double) img.width / 32.0) * 4;
        int size = off * img.height;
        img.data = new unsigned char[size];
        file.read((char *) img.data, size);

        /*unsigned char* tmp = new unsigned char [size];
        for(int i = 0; i < size - off; i += off)
        {
            std::copy(img.data + i, img.data + i + off, tmp + size - off - i);
        }

        img.data = tmp;*/

        Texture2D tex(img);

        return tex;
    }

    void Texture2D::release() {
        if (m_id)
            glDeleteTextures(1, &m_id);
        m_id = 0;
    }
}
