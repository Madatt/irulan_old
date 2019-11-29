//
// Created by madatt on 29.11.19.
//

#include "irulan/System/Resources/Loaders/MeshLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Iru::MeshLoader {
    MeshData loadObj(std::string t_path) {
        std::vector<float> vers;
        std::vector<float> texs;
        std::vector<unsigned char> ind;
        std::vector<float> comb;

        std::ifstream in(t_path);
        std::string curr;

        while(in >> curr)
        {
            if(curr == "v")
            {
                float x, y, z;
                in >> x >> y >> z;
                vers.push_back(x);
                vers.push_back(y);
                vers.push_back(z);
            }else if(curr == "f") {
                234
            }
        }

        return MeshData();
    }
}