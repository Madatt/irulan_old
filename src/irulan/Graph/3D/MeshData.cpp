//
// Created by madatt on 29.11.19.
//

#include "irulan/Graph/3D/MeshData.h"

namespace Iru {
    MeshData::MeshData(std::vector<float> t_vers, std::vector<unsigned char> t_ind) {
        m_vers = t_vers;
        m_ind = t_ind;
    }

}