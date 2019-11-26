//
// Created by Dawid on 24.08.2019.
//

#ifndef RSMOL_VERTEXBUFFER_H
#define RSMOL_VERTEXBUFFER_H

#include "glad/glad.h"
#include <vector>

namespace Iru {
    class VertexBuffer {
        friend class RenderTarget;
        friend class VertexArray;

    public:
        VertexBuffer();
        VertexBuffer(const VertexBuffer& t_r) = delete;
        VertexBuffer(VertexBuffer&& t_r);
        ~VertexBuffer();

        VertexBuffer& operator=(const VertexBuffer& t_r) = delete;
        VertexBuffer& operator=(VertexBuffer&& t_r);


        void setData(unsigned int t_size, void *t_data);
        void setSubData(unsigned int t_offset ,unsigned int t_size, void *t_data);
        void setStorage(unsigned int t_size, void *t_data);
        
    private:
        unsigned int m_id = 0;

        void create();
        void release();
    };

}

#endif //RSMOL_VERTEXBUFFER_H
