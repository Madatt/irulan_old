//
// Created by madatt on 29.11.19.
//

#ifndef IRULAN_MESHLOADER_H
#define IRULAN_MESHLOADER_H

#include "Graph/3D/MeshData.h"

namespace Iru::MeshLoader {
    std::vector<std::string> split(const std::string& t_str, char t_de);
    MeshData loadObj(std::string t_path);
}

#endif //IRULAN_MESHLOADER_H
