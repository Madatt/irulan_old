//
// Created by Dawid on 23.08.2019.
//

#ifndef RSMOL_SHADER_H
#define RSMOL_SHADER_H


#include <string>


namespace Iru {
    class Matrix;

    class Shader {
        friend class Renderer;

    public:
        Shader();
        Shader(std::string t_ver, std::string t_frag);
        ~Shader();

        void setVertex(std::string t_ver);
        void setFragment(std::string t_frag);
        void link();

        void setMatrix(std::string t_name, Matrix &t_mat);
        void setInt(std::string t_name, int t_val);

        bool check();

    private:
        unsigned int m_id = 0;
        unsigned int m_vid = 0;
        unsigned int m_fid = 0;

        void use();
    };
}

#endif //RSMOL_SHADER_H
