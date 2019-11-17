//
// Created by Madatt on 17.11.2019.
//

#ifndef IRULAN_VERTEXTEXTURE_H
#define IRULAN_VERTEXTEXTURE_H

#include "Math/Vector3.h"

namespace Iru {
    class VertexT {
    public:
        VertexT() = default;
        VertexT(Vector3 t_p, Vector3 t_tp);
        ~VertexT() = default;

        float* getPtr(){return t_data;};

    private:
        float t_data[6] = {};
    };
}

#endif //IRULAN_VERTEXTEXTURE_H
