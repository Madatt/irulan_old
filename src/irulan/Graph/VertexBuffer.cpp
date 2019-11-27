//
// Created by Dawid on 24.08.2019.
//

#include "Graph/VertexBuffer.h"
#include "glad/glad.h"

namespace Iru {
    VertexBuffer::VertexBuffer()
            : m_ptr() {

    }

    void VertexBuffer::setData(unsigned int t_size, void *t_data) {
        glNamedBufferData(m_ptr.get(), t_size, t_data, GL_DYNAMIC_DRAW);
    }

    void VertexBuffer::setStorage(unsigned int t_size, void *t_data) {
        glNamedBufferStorage(m_ptr.get(), t_size, t_data, GL_DYNAMIC_STORAGE_BIT);
    }

    void VertexBuffer::setSubData(unsigned int t_offset, unsigned int t_size, void *t_data) {
        glNamedBufferSubData(m_ptr.get(), t_offset, t_size, t_data);
    }
    

}


