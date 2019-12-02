//
// Created by Madatt on 02.12.2019.
//


#include <glad/glad.h>
#include "irulan/System/Memory/Buffer.h"


namespace Iru {
    Buffer::~Buffer() {
        m_bb->ba->free(this);
    }

    Buffer::Buffer(BufferBlock *t_bb) {
        m_bb = t_bb;
    }
}