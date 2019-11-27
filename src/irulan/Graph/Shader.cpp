//
// Created by Dawid on 23.08.2019.
//

#include <iostream>
#include "Graph/Shader.h"
#include "Math/Matrix.h"
#include "glad/glad.h"
#include <iostream>

namespace Iru {
    Shader::Shader()
            : m_ptr() {

    }

    Shader::Shader(std::string t_ver, std::string t_frag)
            : m_ptr() {
        setVertex(t_ver);
        setFragment(t_frag);
        link();
    }

    void Shader::setMatrix(std::string t_name, Matrix t_mat) const {
        if (m_ptr.get())
            glProgramUniformMatrix4fv(m_ptr.get(), glGetUniformLocation(m_ptr.get(), t_name.c_str()), 1, false,
                                      t_mat.getPtr());
    }

    void Shader::setInt(std::string t_name, int t_val) const {
        if (m_ptr.get())
            glProgramUniform1i(m_ptr.get(), glGetUniformLocation(m_ptr.get(), t_name.c_str()), t_val);
    }

    bool Shader::check() {
        return m_ptr.get();
    }

    void Shader::setVertex(std::string t_ver) {
        if (m_vid)
            return;

        const char *ver_c = t_ver.c_str();
        char msg[512];
        int succ;

        m_vid = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(m_vid, 1, &ver_c, NULL);
        glCompileShader(m_vid);
        glGetShaderiv(m_vid, GL_COMPILE_STATUS, &succ);
        if (!succ) {
            glGetShaderInfoLog(m_vid, 512, NULL, msg);
            std::cout << "[Error] Vertex compilation failed: " << msg << std::endl;
            m_vid = 0;
        }
    }

    void Shader::setFragment(std::string t_frag) {
        if (m_fid)
            return;

        const char *frag_c = t_frag.c_str();
        char msg[512];
        int succ;

        m_fid = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(m_fid, 1, &frag_c, NULL);
        glCompileShader(m_fid);
        glGetShaderiv(m_fid, GL_COMPILE_STATUS, &succ);
        if (!succ) {
            glGetShaderInfoLog(m_fid, 512, NULL, msg);
            std::cout << "[Error] Fragment compilation failed: " << msg << std::endl;
            m_fid = 0;
        }
    }

    void Shader::link() {
        char msg[512];
        int succ;

        if (!m_fid || !m_vid)
            return;

        glAttachShader(m_ptr.get(), m_vid);
        glAttachShader(m_ptr.get(), m_fid);
        glLinkProgram(m_ptr.get());

        glGetProgramiv(m_ptr.get(), GL_LINK_STATUS, &succ);
        if (!succ) {
            glGetProgramInfoLog(m_ptr.get(), 512, NULL, msg);
            std::cout << "[Error] Shader linking failed: " << msg << std::endl;
        }

        glDeleteShader(m_fid);
        glDeleteShader(m_vid);
    }

}