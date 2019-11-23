//
// Created by Dawid on 25.08.2019.
//

#ifndef RSMOL_VERTEXARRAY_H
#define RSMOL_VERTEXARRAY_H

#include "Defines.h"

namespace Iru {
    class VertexBuffer;

    class VertexArray {
        friend class RenderTarget;

    public:
        VertexArray() = default;
        VertexArray(const VertexArray& t_r) = delete;
        VertexArray(VertexArray&& t_r);
        ~VertexArray();

        VertexArray& operator=(const VertexArray& t_r) = delete;
        VertexArray& operator=(VertexArray&& t_r);

        void attachVB(const VertexBuffer &t_vb, unsigned int t_i, unsigned int t_start , unsigned int t_stride);
        void attachIB(const VertexBuffer &t_vb);
        void setAttrib(unsigned int t_vi , unsigned int t_i, unsigned int t_count, unsigned int t_off) const;

    private:
        unsigned int m_id = 0;

        void create();
        void release();
    };
}


#endif //RSMOL_VERTEXARRAY_H
