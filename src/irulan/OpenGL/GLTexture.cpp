//
// Created by Madatt on 27.11.2019.
//

#include "irulan/OpenGL/GLTexture.h"
#include "glad.h"

namespace Iru {
    unsigned int GLTexture::create() {
        unsigned int tmp;
        glCreateTextures(GL_TEXTURE_2D, 1, &tmp);
        return tmp;
    }

    void GLTexture::release(unsigned int t_id) {
        glDeleteTextures(1, &t_id);
    }
}