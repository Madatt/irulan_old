//
// Created by Madatt on 02.12.2019.
//

#ifndef IRULAN_ANIMATEDMESHFRAME_H
#define IRULAN_ANIMATEDMESHFRAME_H

#include <vector>
#include <irulan/irulan.h>

namespace Iru {
    class AnimatedMeshFrame {
    public:
        AnimatedMeshFrame(const MeshData& m_ori, const MeshData& m_nxt);

    private:
        std::vector<std::pair<int, Vector3f>> m_vers;
    };
}

#endif //IRULAN_ANIMATEDMESHFRAME_H
