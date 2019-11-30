//
// Created by Madatt on 27.11.2019.
//

#include "irulan/System/Resources/ResourceManager.h"

namespace Iru
{
    void ResourceManager::removeResource(std::string t_name) {
        m_res.erase(t_name);
    }
}