//
// Created by Madatt on 17.11.2019.
//

#include "Graph/Primitives/VertexT.h"


namespace Iru
{
    VertexT::VertexT(Vector3 t_p, Vector3 t_tp) {
        t_data[0] = t_p.x;
        t_data[1] = t_p.y;
        t_data[2] = t_p.z;
        t_data[3] = t_tp.x;
        t_data[4] = t_tp.y;
        t_data[5] = t_tp.z;
    }
}