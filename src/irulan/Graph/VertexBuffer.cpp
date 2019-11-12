//
// Created by Dawid on 24.08.2019.
//

#include "Graph/VertexBuffer.h"
#include "glad/glad.h"

namespace Iru {
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_id);
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_id);
    }

    void VertexBuffer::use() {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::setData(signed long int t_size, void *t_data) {
        use();
        glBufferData(GL_ARRAY_BUFFER, t_size, t_data, GL_STATIC_DRAW);
    }

    template<typename T>
    void VertexBuffer::setData(std::vector<T> t_data) {
        use();
        glBufferData(GL_ARRAY_BUFFER, sizeof(T) * t_data.size(), t_data.data(), GL_STATIC_DRAW);
    }
}


