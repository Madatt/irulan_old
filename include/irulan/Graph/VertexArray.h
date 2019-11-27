//
// Created by Dawid on 25.08.2019.
//

#ifndef RSMOL_VERTEXARRAY_H
#define RSMOL_VERTEXARRAY_H

#include "Defines.h"
#include "OpenGL/GLObject.h"

namespace Iru {
    class VertexBuffer;

    class VertexArray {
        friend class RenderTarget;

    public:
        VertexArray();

        void attachVB(const VertexBuffer &t_vb, unsigned int t_i, unsigned int t_start , unsigned int t_stride);
        void attachIB(const VertexBuffer &t_vb);
        void setAttrib(unsigned int t_vi , unsigned int t_i, unsigned int t_count, unsigned int t_off) const;

    private:
        GLObject<GLVertexArray> m_ptr;

    };
}


#endif //RSMOL_VERTEXARRAY_H
