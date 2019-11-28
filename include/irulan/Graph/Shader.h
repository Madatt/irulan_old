//
// Created by Dawid on 23.08.2019.
//

#ifndef RSMOL_SHADER_H
#define RSMOL_SHADER_H


#include <string>
#include "System/OpenGL/GLObject.h"
#include "System/Resources/Resource.h"


namespace Iru {
    class Matrix;

    class Shader : public Resource {
        friend class RenderTarget;

    public:
        Shader();
        Shader(std::string t_ver, std::string t_frag);
        ~Shader() override;

        void setVertex(std::string t_ver);
        void setFragment(std::string t_frag);
        void link();

        void setMatrix(std::string t_name, Matrix t_mat) const;
        void setInt(std::string t_name, int t_val) const;

        bool check();

    private:
        GLObject<GLShader> m_ptr;
        unsigned int m_vid = 0;
        unsigned int m_fid = 0;
    };
}

#endif //RSMOL_SHADER_H
