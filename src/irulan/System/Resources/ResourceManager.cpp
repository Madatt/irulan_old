//
// Created by Madatt on 27.11.2019.
//

#include "irulan/System/Resources/ResourceManager.h"

namespace Iru
{
    void ResourceManager::addResource(std::string t_name, Resource *t_r) {
        m_res.insert(std::make_pair(t_name, t_r));
    }

    void ResourceManager::removeResource(std::string t_name) {
        m_res.erase(t_name);
    }
}