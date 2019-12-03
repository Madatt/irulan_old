//
// Created by Madatt on 02.12.2019.
//

#include "irulan/System/Memory/Buffer.h"


namespace Iru {
    Buffer::~Buffer() {
        m_bb->ba->free(this);
    }

    Buffer::Buffer(BufferBlock *t_bb)
            : m_bb(t_bb) {
    }

    void Buffer::setData(unsigned int t_size, unsigned int t_off, void *t_data) {
        memcpy((void *) ((int) (m_bb->ptr) + t_off + m_bb->offset), t_data, t_size);
    }
}