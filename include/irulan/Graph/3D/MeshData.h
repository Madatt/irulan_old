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
        MeshData() = default;
        MeshData(std::vector<float> t_vers, std::vector<unsigned char> t_ind);
        ~MeshData() = default;

        const std::vector<float>& getData() const {return m_vers;};
        const std::vector<unsigned char>& getInd() const {return m_ind;};
    private:
        std::vector<float> m_vers;
        std::vector<unsigned char> m_ind;

    };
}

#endif //IRULAN_MESHDATA_H
