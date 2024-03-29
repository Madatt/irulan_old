//
// Created by Dawid on 25.08.2019.
//

#include <iostream>
#include "Graph/VertexArray.h"
#include "Graph/VertexBuffer.h"
#include "glad/glad.h"

namespace Iru {

    VertexArray::VertexArray()
            : m_ptr() {

    }


    void
    VertexArray::attachVB(const VertexBuffer &t_vb, unsigned int t_i, unsigned int t_start, unsigned int t_stride) {
        glVertexArrayVertexBuffer(m_ptr.get(), t_i, t_vb.m_ptr.get(), t_start, t_stride);
    }

    void VertexArray::attachVB(const Buffer *t_b, unsigned int t_i, unsigned int t_start, unsigned int t_stride) {
        glVertexArrayVertexBuffer(m_ptr.get(), t_i, t_b->m_bb->vb, t_b->m_bb->offset + t_start, t_stride);
    }

    void VertexArray::attachIB(const VertexBuffer &t_vb) {
        glVertexArrayElementBuffer(m_ptr.get(), t_vb.m_ptr.get());
        m_i_off = 0;
    }

    void VertexArray::attachIB(const Buffer* t_b) {
        glVertexArrayElementBuffer(m_ptr.get(), t_b->m_bb->vb);
        m_i_off = t_b->m_bb->offset;
    }
    void VertexArray::setAttrib(unsigned int t_vi, unsigned int t_i, unsigned int t_count, unsigned int t_off) {
        glBindVertexArray(m_ptr.get());

        glEnableVertexArrayAttrib(m_ptr.get(), t_i);

        glVertexArrayAttribFormat(m_ptr.get(), t_i, t_count, GL_FLOAT, GL_FALSE, t_off);

        glVertexArrayAttribBinding(m_ptr.get(), t_i, t_vi);
    }


}


