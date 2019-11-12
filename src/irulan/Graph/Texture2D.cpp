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
    }

    Texture2D::Texture2D(Image t_img, Format t_for) {
        m_width = t_img.width;
        m_height = t_img.height;

        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, t_img.width, t_img.height, 0, t_for, GL_UNSIGNED_BYTE, t_img.data);
    }

    Texture2D::Texture2D(int t_w, int t_h) {
        m_width = t_w;
        m_height = t_h;

        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, t_w, t_h, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
    }

    Texture2D::Texture2D(int t_w, int t_h, Format t_f) {
        m_width = t_w;
        m_height = t_h;

        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, t_f, t_w, t_h, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

    }

    void Texture2D::generate(){
        if(!m_id)
            return;
        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
    }

    void Texture2D::setData(int t_x, int t_y, int t_w, int t_h, Format t_f, void *data) {
        if (!m_id)
            return;
        glTextureSubImage2D(m_id, 0, t_x, t_y, t_w, t_h, t_f, GL_UNSIGNED_BYTE, data);
    }

    void Texture2D::setFiltering(Filtering t_fil) {
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, t_fil);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, t_fil);
    }


    Texture2D Texture2D::_loadBMP(std::string t_path) {
        std::ifstream file(t_path, std::ios::binary);
        if (!file.is_open()) {
            std::cout << "asdas";
        }

        char info[54];
        file.read(info, 54);

        Image img;
        int pos;

        memcpy(&img.width, info + 18, sizeof(int));
        memcpy(&img.height, info + 22, sizeof(int));
        memcpy(&pos, info + 0x0A, sizeof(int));

        file.seekg(pos, file.beg);

        int off = std::ceil(24.0 * (double)img.width / 32.0) * 4;
        int size = off * img.height ;
        img.data = new unsigned char [size];

        file.read((char*)img.data, size);

        Texture2D tex(img, BGR);

        return tex;
    }
}
