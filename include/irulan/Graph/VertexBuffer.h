//
// Created by Dawid on 24.08.2019.
//

#ifndef RSMOL_VERTEXBUFFER_H
#define RSMOL_VERTEXBUFFER_H

#include <vector>

namespace Iru {
    class VertexBuffer {
        friend class RenderTarget;
        friend class VertexArray;

    public:
        VertexBuffer() = default;
        VertexBuffer(const VertexBuffer& t_r) = delete;
        VertexBuffer(VertexBuffer&& t_r);
        ~VertexBuffer();

        VertexBuffer& operator=(const VertexBuffer& t_r) = delete;
        VertexBuffer& operator=(VertexBuffer&& t_r);


        void setData(signed long int t_size, void *t_data);
        template<typename T>
        void setData(std::vector<T> t_data);

    private:
        unsigned int m_id = 0;

        void use();
        void create();
        void release();
    };
}

#endif //RSMOL_VERTEXBUFFER_H
