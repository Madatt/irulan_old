//
// Created by Madatt on 01.12.2019.
//

#ifndef IRULAN_ANIMATEDMESHDATA_H
#define IRULAN_ANIMATEDMESHDATA_H


#include <irulan/System/Resources/Resource.h>
#include "MeshData.h"

namespace Iru {
    class AnimatedMeshData : public Resource{
    public:
        AnimatedMeshData() = default;
        ~AnimatedMeshData() override = default;

        void addFrame(MeshData* t_md);
        MeshData* getFrame(int t_i) const;
        int getLength() const;
        int getPrimitives() const;
    private:
        std::vector<MeshData*> m_frames;
        int m_pn = -1;
    };
}

#endif //IRULAN_ANIMATEDMESHDATA_H
