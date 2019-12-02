//
// Created by Madatt on 02.12.2019.
//

#include <irulan/System/Memory/Buffer.h>
#include <glad/glad.h>
#include <iostream>
#include "irulan/System/Memory/BufferAllocator.h"

namespace Iru {
    BufferAllocator::BufferAllocator() {
        newBlock(POOL_SIZE);
    }

    Buffer *BufferAllocator::allocate(int t_size) {
        for(auto curr = m_head; curr != nullptr; curr = curr->next)
        {
            if(curr->size >= t_size and curr->free)
            {
                unsigned int ns = curr->size - t_size;
                auto bf = new Buffer(curr);
                curr->free = false;
                curr->size = t_size;

                std::cout << "Allocated: " << t_size << ", vb: " << curr->vb << std::endl;
                if(ns > 0)
                {
                    auto nb = new BufferBlock;
                    nb->vb = curr->vb;
                    nb->free = true;
                    nb->size = ns;
                    nb->id = m_nid++;
                    nb->next = curr->next;
                    nb->offset = curr->offset + t_size;
                    nb->ptr = curr->ptr;
                    curr->next = nb;
                    std::cout << "New block: " << ns << ", offset: " << (int)(nb->ptr) + nb->offset << ", vb: " << nb->vb << std::endl;
                }

                return bf;
            }
        }

        newBlock(POOL_SIZE);
        return allocate(t_size);
    }

    void BufferAllocator::free(Buffer *t_bf) {
        t_bf->m_bb->free = true;
    }

    void BufferAllocator::newBlock(int t_size) {
        if(m_head == nullptr)
        {
            m_head = new BufferBlock;
            m_head->free = true;
            m_head->size = t_size;
            m_head->id = m_nid++;
            glCreateBuffers(1, &(m_head->vb));
            glNamedBufferStorage(m_head->vb, t_size, nullptr, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
            m_head->ptr = glMapNamedBufferRange(m_head->vb, 0, t_size, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
        }else {
            auto nw = new BufferBlock;
            m_head->last()->next = nw;
            nw->free = true;
            nw->size = t_size;
            nw->id = m_nid++;
            glCreateBuffers(1, &(nw->vb));
            glNamedBufferStorage(nw->vb, t_size, nullptr, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
            nw->ptr = glMapNamedBufferRange(nw->vb, 0, t_size, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
        }

    }
}