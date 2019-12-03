//
// Created by Madatt on 02.12.2019.
//

#ifndef IRULAN_BUFFERALLOCATOR_H
#define IRULAN_BUFFERALLOCATOR_H

namespace Iru {
    const unsigned int POOL_SIZE = sizeof(float) * 3 * 10000;

    class BufferAllocator;
    class Buffer;

    struct BufferBlock {
        unsigned int vb = 0;
        unsigned int id = 0;
        unsigned int size = 0;
        unsigned int offset = 0;
        bool free = true;

        BufferAllocator* ba = nullptr;
        BufferBlock* next = nullptr;

        void* ptr = nullptr;

        BufferBlock* last() {
            if(next == nullptr)
                return this;
            else return next->last();
        }
    };

    class BufferAllocator {
    public:
        BufferAllocator();
        ~BufferAllocator() = default;

        Buffer* allocate(int t_size);
        void free(Buffer* t_bf);

    private:
        BufferBlock* m_head = nullptr;
        unsigned int m_nid = 0;

        void newBlock(int t_size);
        void swipe();
    };
}

#endif //IRULAN_BUFFERALLOCATOR_H
