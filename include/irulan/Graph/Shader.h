//
// Created by Dawid on 23.08.2019.
//

#ifndef RSMOL_SHADER_H
#define RSMOL_SHADER_H


#include <string>


namespace Iru {
    class Matrix;

    class Shader {
        friend class RenderTarget;

    public:
        Shader();
        Shader(std::string t_ver, std::string t_frag);
        Shader(const Shader& t_r) = delete;
        Shader(Shader&& t_r);
        ~Shader();

        Shader& operator=(const Shader& t_r) = delete;
        Shader& operator=(Shader&& t_r);

        void setVertex(std::string t_ver);
        void setFragment(std::string t_frag);
        void link();

        void setMatrix(std::string t_name, Matrix t_mat) const;
        void setInt(std::string t_name, int t_val) const;

        bool check();

    private:
        void release();

        unsigned int m_id = 0;
        unsigned int m_vid = 0;
        unsigned int m_fid = 0;
    };
}

#endif //RSMOL_SHADER_H
