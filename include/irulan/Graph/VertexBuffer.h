//
// Created by Dawid on 24.08.2019.
//

#ifndef RSMOL_VERTEXBUFFER_H
#define RSMOL_VERTEXBUFFER_H

#include "glad/glad.h"
#include "System/OpenGL/GLObject.h"
#include <vector>

namespace Iru {
    class VertexBuffer {
        friend class RenderTarget;
        friend class VertexArray;

    public:
        VertexBuffer();

        void setData(unsigned int t_size, void *t_data);
        void setSubData(unsigned int t_offset ,unsigned int t_size, void *t_data);
        void setStorage(unsigned int t_size, void *t_data);
        
    private:
        GLObject<GLVertexBuffer> m_ptr;

    };

}

#endif //RSMOL_VERTEXBUFFER_H
