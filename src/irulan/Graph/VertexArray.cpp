//
// Created by Dawid on 25.08.2019.
//

#include <iostream>
#include "Graph/VertexArray.h"
#include "Graph/VertexBuffer.h"
#include "glad/glad.h"

namespace Iru {

    VertexArray::VertexArray(VertexArray &&t_r) {
        m_id = t_r.m_id;
        t_r.m_id = 0;
    }

    VertexArray::~VertexArray() {
        release();
    }

    VertexArray &VertexArray::operator=(VertexArray &&t_r) {
        if(this != &t_r)
        {
            release();
            m_id = t_r.m_id;

            t_r.m_id = 0;
        }
        return *this;
    }


    void VertexArray::use() {
        glBindVertexArray(m_id);
    }

    void VertexArray::bindData(VertexBuffer *t_vb, unsigned int t_i ,unsigned int t_start, unsigned int t_size) {
        create();
        glVertexArrayVertexBuffer(m_id, t_i, t_vb->m_id, t_start, t_size);
    }

    void VertexArray::setAttrib(unsigned int t_vi , unsigned int t_i, unsigned int t_count, unsigned int t_off) {
        glBindVertexArray(m_id);

        glEnableVertexArrayAttrib(m_id, t_i);

        glVertexArrayAttribFormat(m_id, t_i, t_count, GL_FLOAT, GL_FALSE, t_off);

        glVertexArrayAttribBinding(m_id, t_i, t_vi);
    }

    void VertexArray::create() {
        if(!m_id)
            glCreateVertexArrays(1, &m_id);
    }

    void VertexArray::release() {
        if(m_id)
            glDeleteVertexArrays(1, &m_id);
        m_id = 0;
    }

}


