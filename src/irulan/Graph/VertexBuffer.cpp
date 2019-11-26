//
// Created by Dawid on 24.08.2019.
//

#include "Graph/VertexBuffer.h"
#include "glad/glad.h"

namespace Iru {
    VertexBuffer::VertexBuffer() {
        create();
    }

    VertexBuffer::VertexBuffer(VertexBuffer &&t_r) {
        m_id = t_r.m_id;
        t_r.m_id = 0;
    }

    VertexBuffer::~VertexBuffer() {
        release();
    }

    VertexBuffer &VertexBuffer::operator=(VertexBuffer &&t_r) {
        if(this != &t_r)
        {
            release();
            m_id = t_r.m_id;

            t_r.m_id = 0;
        }
        return *this;
    }

    void VertexBuffer::setData(unsigned int t_size, void *t_data) {
        glNamedBufferData(m_id, t_size, t_data, GL_DYNAMIC_DRAW);
    }

    void VertexBuffer::setStorage(unsigned int t_size, void *t_data) {
        glNamedBufferStorage(m_id, t_size, t_data, GL_DYNAMIC_STORAGE_BIT);
    }

    void VertexBuffer::setSubData(unsigned int t_offset, unsigned int t_size, void *t_data) {
        glNamedBufferSubData(m_id, t_offset, t_size, t_data);
    }

    void VertexBuffer::create() {
        if(!m_id)
            glCreateBuffers(1, &m_id);
    }

    void VertexBuffer::release() {
        if(m_id)
            glDeleteBuffers(1, &m_id);

        m_id = 0;
    }

}


