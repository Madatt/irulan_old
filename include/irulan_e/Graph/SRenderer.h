//
// Created by madatt on 12.11.19.
//

#ifndef IRULAN_SRENDERER_H
#define IRULAN_SRENDERER_H

#include "Graph/Renderer.h"

namespace IruE {
    template<typename T>
    class SRenderer {
    public:
        SRenderer(Iru::Renderer& t_ren)
        :m_ren(&t_ren){};

        virtual void draw(T t_d);
    protected:
        Iru::Renderer* m_ren = nullptr;
    };
}

#endif //IRULAN_SRENDERER_H
