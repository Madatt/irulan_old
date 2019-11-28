//
// Created by Madatt on 27.11.2019.
//

#include "irulan/System/OpenGL/GLTraits.h"
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

    unsigned int GLShader::create() {
        return glCreateProgram();
    }

    void GLShader::release(unsigned int t_id) {
        glDeleteProgram(t_id);
    }

    unsigned int GLVertexArray::create() {
        unsigned int tmp;
        glCreateVertexArrays(1, &tmp);
        return tmp;
    }

    void GLVertexArray::release(unsigned int t_id) {
        glDeleteVertexArrays(1, &t_id);
    }

    unsigned int GLVertexBuffer::create() {
        unsigned int tmp;
        glCreateBuffers(1, &tmp);
        return tmp;
    }

    void GLVertexBuffer::release(unsigned int t_id) {
        glDeleteBuffers(1, &t_id);
    }
}