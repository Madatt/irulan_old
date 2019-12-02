//
// Created by Madatt on 02.12.2019.
//

#ifndef IRULAN_BUFFER_H
#define IRULAN_BUFFER_H

#include "BufferAllocator.h"
#include <algorithm>
#include <memory.h>

namespace Iru {
    class Buffer {
    friend class VertexArray;
    friend class BufferAllocator;
    public:
        ~Buffer();


        void setData(unsigned int t_size, unsigned int t_off, void* t_data) {
            memcpy((void*)((int)(m_bb->ptr) + t_off + m_bb->offset), t_data, t_size);
        }

    private:
        BufferBlock* m_bb;

        Buffer() = delete;
        Buffer(BufferBlock* t_bb);

    };
}

#endif //IRULAN_BUFFER_H
