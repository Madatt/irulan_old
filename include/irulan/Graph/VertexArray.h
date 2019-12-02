//
// Created by Dawid on 25.08.2019.
//

#ifndef RSMOL_VERTEXARRAY_H
#define RSMOL_VERTEXARRAY_H

#include <irulan/System/Memory/Buffer.h>
#include "irulan/System/Defines.h"
#include "System/OpenGL/GLObject.h"

namespace Iru {
    class VertexBuffer;

    class VertexArray {
        friend class RenderTarget;

    public:
        VertexArray();

        void attachVB(const VertexBuffer &t_vb, unsigned int t_i, unsigned int t_start ,unsigned int t_stride);
        void attachVB(const Buffer *t_b, unsigned int t_i, unsigned int t_start , unsigned int t_stride);
        void attachIB(const VertexBuffer &t_vb);
        void attachIB(const Buffer *t_b);
        void setAttrib(unsigned int t_vi , unsigned int t_i, unsigned int t_count, unsigned int t_off);

    private:
        GLObject<GLVertexArray> m_ptr;

    };
}


#endif //RSMOL_VERTEXARRAY_H
