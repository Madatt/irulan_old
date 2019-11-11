//
// Created by Dawid on 05.09.2019.
//


#include <iostream>
#include <Defines.h>
#include "Graph/Renderer.h"
#include "Graph/Shader.h"
#include "Graph/Texture.h"
#include "Graph/VertexArray.h"
#include "Graph/VertexBuffer.h"


namespace Iru {
    Renderer::Renderer() {
        for (auto & i : m_texture) {
            i = nullptr;
        }
    }

    void Renderer::setShader(Shader *t_sha) {
        m_shader = t_sha;
    }

    void Renderer::setVA(VertexArray *t_va) {
        m_va = t_va;
    }

    void Renderer::drawArrays(Polygon t_type, int t_s, int t_c) {
        if (m_shader == nullptr || m_va == nullptr)
            return;

        for (int i = 0; i < 16; i++) {
            if (m_texture[i] != nullptr) {
                glActiveTexture(GL_TEXTURE0 + i);
                glBindTexture(GL_TEXTURE_2D, m_texture[i]->m_id);
            }
        }

        m_va->use();
        m_shader->use();

        glDrawArrays(t_type, t_s, t_c);
    }

    void Renderer::flush() {
        m_shader = nullptr;
        m_va = nullptr;

        for (int i = 0; i < 16; i++) {
            m_texture[i] = nullptr;
        }
    }

    void Renderer::setTexture(Texture *t_tex, int t_n) {
        m_texture[t_n] = t_tex;
    }


    void Renderer::clear() {
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        flush();
    }
}