//
// Created by madatt on 29.11.19.
//

#ifndef IRULAN_MESHDATA_H
#define IRULAN_MESHDATA_H

#include <vector>
#include <string>
#include "System/Resources/Resource.h"

namespace Iru {
    class MeshData : public Resource{
    public:
        MeshData(std::vector<float> t_vers, int t_pn);
        ~MeshData() = default;

        const std::vector<float>& getData() const {return m_vers;};
        int getTriangles() const {return m_pn;};
    private:
        std::vector<float> m_vers;
        int m_pn = 0;

    };
}

#endif //IRULAN_MESHDATA_H
