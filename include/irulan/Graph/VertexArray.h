//
// Created by Dawid on 25.08.2019.
//

#ifndef RSMOL_VERTEXARRAY_H
#define RSMOL_VERTEXARRAY_H

#include "Defines.h"

namespace Iru {
    class VertexBuffer;

    class VertexArray {
        friend class Renderer;

    public:
        VertexArray();
        ~VertexArray();
        void setAttrib(VertexBuffer &t_vb, unsigned int t_i, unsigned int t_size, Type t_type, unsigned int t_stride,
                       void *t_data);

        void enableAttrib(unsigned int t_i);

    private:
        unsigned int m_id;

        void use();
    };
}


#endif //RSMOL_VERTEXARRAY_H
