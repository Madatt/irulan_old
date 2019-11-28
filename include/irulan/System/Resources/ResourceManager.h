//
// Created by Madatt on 27.11.2019.
//

#ifndef IRULAN_RESOURCEMANAGER_H
#define IRULAN_RESOURCEMANAGER_H

#include "Resource.h"
#include <iostream>
#include <unordered_map>


namespace Iru {
    class ResourceManager {
    public:

        template <typename T> const T* getResource(std::string t_name);
        void addResource(std::string t_name, Resource* t_r);
        void removeResource(std::string t_name);

    private:
        std::unordered_map <std::string, Resource*> m_res;
    };

    template<typename T>
    const T *ResourceManager::getResource(std::string t_name) {
        return dynamic_cast<T*>(m_res[t_name]);
    }


}

#endif //IRULAN_RESOURCEMANAGER_H
