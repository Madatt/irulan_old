//
// Created by Madatt on 01.12.2019.
//

#include "irulan/Graph/3D/Mesh/AnimatedMeshData.h"

namespace Iru {
    void AnimatedMeshData::addFrame(MeshData *t_md) {
        if(t_md->getTriangles() == m_pn or m_pn < 0)
        {
            m_frames.push_back(t_md);
            m_pn = t_md->getTriangles();
        }
    }

    MeshData* AnimatedMeshData::getFrame(int t_i) const{
        return m_frames[t_i];
    }

    int AnimatedMeshData::getLength() const {
        return m_frames.size();
    }

    int AnimatedMeshData::getPrimitives() const {
        return m_pn;
    }
}