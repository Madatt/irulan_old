//
// Created by Dawid on 24.08.2019.
//

#include "Graph/VertexBuffer.h"
#include "glad/glad.h"

namespace Iru {
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
    void VertexBuffer::use() {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::setData(signed long int t_size, void *t_data) {
        create();
        glNamedBufferData(m_id, t_size, t_data, GL_STATIC_DRAW);
    }

    template<typename T>
    void VertexBuffer::setData(std::vector<T> t_data) {
        create();
        glNamedBufferData(m_id, sizeof(T) * t_data.size(), t_data.data(), GL_STATIC_DRAW);
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


