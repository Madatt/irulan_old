//
// Created by Dawid on 25.08.2019.
//

#include "Graph/VertexArray.h"
#include "Graph/VertexBuffer.h"
#include "glad/glad.h"

namespace Iru {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_id);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_id);
    }

    void VertexArray::use() {
        glBindVertexArray(m_id);
    }

    void VertexArray::setAttrib(VertexBuffer &t_vb, unsigned int t_i, unsigned int t_size, Type t_type,
                                unsigned int t_stride, void *t_data) {
        use();
        t_vb.use();
        glVertexAttribPointer(t_i, t_size, t_type, GL_FALSE, t_stride, t_data);
        enableAttrib(t_i);
    }

    void VertexArray::enableAttrib(unsigned int t_i) {
        use();
        glEnableVertexAttribArray(t_i);
    }
}


