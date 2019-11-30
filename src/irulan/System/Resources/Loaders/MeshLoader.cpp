//
// Created by madatt on 29.11.19.
//

#include "irulan/System/Resources/Loaders/MeshLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

namespace Iru::MeshLoader {
    std::vector<std::string> split(const std::string &t_str, char t_de) {
        std::vector<std::string> results;
        std::stringstream ss(t_str);
        std::string item;
        while (std::getline(ss, item, t_de)) {
            results.push_back(item);
        }
        return results;
    }


    MeshData loadObj(std::string t_path) {
        std::vector<float> vers;
        std::vector<float> texs;
        std::vector<unsigned char> ind;
        std::vector<float> comb;

        std::ifstream in(t_path);
        std::string curr;

        while (in >> curr) {
            if (curr == "v") {
                float x, y, z;
                in >> x >> y >> z;
                vers.push_back(x);
                vers.push_back(y);
                vers.push_back(z);
                //std::cout << "v " << x << " " << y << " " << z << std::endl;
            } else if (curr == "f") {
                std::string x, y, z;
                std::vector<std::string> px, py, pz;
                in >> x >> y >> z;
                px = split(x, '/');
                py = split(y, '/');
                pz = split(z, '/');


                comb.push_back(vers[(std::stoi(px[0]) - 1) * 3]);
                comb.push_back(vers[(std::stoi(px[0]) - 1) * 3 + 1]);
                comb.push_back(vers[(std::stoi(px[0]) - 1) * 3 + 2]);
                comb.push_back(vers[(std::stoi(pz[0]) - 1) * 3]);
                comb.push_back(vers[(std::stoi(pz[0]) - 1) * 3 + 1]);
                comb.push_back(vers[(std::stoi(pz[0]) - 1) * 3 + 2]);
                comb.push_back(vers[(std::stoi(py[0]) - 1) * 3]);
                comb.push_back(vers[(std::stoi(py[0]) - 1) * 3 + 1]);
                comb.push_back(vers[(std::stoi(py[0]) - 1) * 3 + 2]);




                //std::cout << "f " << std::stoi(px[0]) - 1 << " " << std::stoi(py[0]) - 1 << " " << std::stoi(pz[0]) - 1 << std::endl;
                //std::cout << std::stoi(px[0]) - 1<< std::endl;
            }
        }


        return MeshData(comb, ind);
    }
}