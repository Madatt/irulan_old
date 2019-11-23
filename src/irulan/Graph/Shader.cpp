//
// Created by Dawid on 23.08.2019.
//

#include <iostream>
#include "Graph/Shader.h"
#include "Math/Matrix.h"
#include "glad/glad.h"
#include <iostream>

namespace Iru {
    Shader::Shader() {

    }

    Shader::Shader(std::string t_ver, std::string t_frag) {
        setVertex(t_ver);
        setFragment(t_frag);
        link();
    }

    Shader::Shader(Shader &&t_r) {
        m_id = t_r.m_id;
        m_vid = t_r.m_vid;
        m_fid = t_r.m_fid;

        t_r.m_id = 0;
        t_r.m_vid = 0;
        t_r.m_fid = 0;

    }

    Shader &Shader::operator=(Shader &&t_r) {
        if(this != &t_r)
        {
            release();
            m_id = t_r.m_id;
            m_vid = t_r.m_vid;
            m_fid = t_r.m_fid;

            t_r.m_id = 0;
            t_r.m_vid = 0;
            t_r.m_fid = 0;
        }
        return *this;
    }

    Shader::~Shader() {
        release();
    }

    void Shader::setMatrix(std::string t_name, Matrix t_mat) const{
        if(m_id)
            glProgramUniformMatrix4fv(m_id ,glGetUniformLocation(m_id, t_name.c_str()), 1, false, t_mat.getPtr());
    }

    void Shader::setInt(std::string t_name, int t_val) const{
        if(m_id)
            glProgramUniform1i(m_id, glGetUniformLocation(m_id, t_name.c_str()), t_val);
    }

    bool Shader::check() {
        return m_id;
    }

    void Shader::setVertex(std::string t_ver) {
        if (m_vid || m_id)
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
        if (m_fid || m_id)
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

        if (m_id)
            return;

        if (!m_fid || !m_vid)
            return;

        m_id = glCreateProgram();
        glAttachShader(m_id, m_vid);
        glAttachShader(m_id, m_fid);
        glLinkProgram(m_id);

        glGetProgramiv(m_id, GL_LINK_STATUS, &succ);
        if (!succ) {
            glGetProgramInfoLog(m_id, 512, NULL, msg);
            std::cout << "[Error] Shader linking failed: " << msg << std::endl;
            m_id = 0;
        }

        glDeleteShader(m_fid);
        glDeleteShader(m_vid);
    }

    void Shader::release() {
        if (m_id)
            glDeleteProgram(m_id);

        if (m_vid)
            glDeleteShader(m_vid);

        if (m_fid)
            glDeleteShader(m_fid);

        m_id = 0;
        m_vid = 0;
        m_fid = 0;
    }

}