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
        std::vector<float> norms;
        std::vector<float> texs;
        std::vector<unsigned char> ind;
        std::vector<float> comb;

        std::ifstream in(t_path);
        std::string curr;

        std::vector<std::string> v[3];
        std::string vs[3];

        int pn = 0;

        while (in >> curr) {
            if (curr == "v") {
                float x, y, z;
                in >> x >> y >> z;
                vers.push_back(x);
                vers.push_back(y);
                vers.push_back(z);
            } else if (curr == "vn") {
                float x, y, z;
                in >> x >> y >> z;
                norms.push_back(x);
                norms.push_back(y);
                norms.push_back(z);
            } else if (curr == "vt") {
                unsigned char x, y;
                in >> x >> y;
                texs.push_back(x);
                texs.push_back(y);
            } else if (curr == "f") {
                pn++;
                in >> vs[0] >> vs[1] >> vs[2];
                v[0] = split(vs[0], '/');
                v[1] = split(vs[1], '/');
                v[2] = split(vs[2], '/');

                for (auto &i : v) {
                    comb.push_back(vers[(std::stoi(i[0]) - 1) * 3]);
                    comb.push_back(vers[(std::stoi(i[0]) - 1) * 3 + 1]);
                    comb.push_back(vers[(std::stoi(i[0]) - 1) * 3 + 2]);
                    if (i.size() > 1 and !i[1].empty()) {
                        comb.push_back(norms[(std::stoi(i[1]) - 1) * 3]);
                        comb.push_back(norms[(std::stoi(i[1]) - 1) * 3 + 1]);
                        comb.push_back(norms[(std::stoi(i[1]) - 1) * 3 + 2]);
                    }
                    if (i.size() == 3) {
                        norms.push_back(texs[(std::stoi(i[1]) - 1) * 3]);
                        norms.push_back(texs[(std::stoi(i[1]) - 1) * 3 + 1]);
                    }
                }
            }
        }


        return MeshData(comb, pn);
    }
}