//
// Created by madatt on 29.11.19.
//

#include "irulan/Graph/3D/Mesh/MeshData.h"

namespace Iru {
    MeshData::MeshData(std::vector<float> t_vers, int t_pn) {
        m_vers = t_vers;
        m_pn = t_pn;
    }

}