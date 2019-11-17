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

    void Renderer::draw(Polygon t_type, int t_s, int t_c) {
        if (m_shader == nullptr || m_va == nullptr)
            return;

        for (int i = 0; i < 16; i++) {
            if (m_texture[i] != nullptr) {
                glBindTextureUnit(i, m_texture[i]->m_id);
                //glBindImageTexture(0, m_texture[i]->m_id, 0, false, 0, GL_READ_ONLY, GL_RGBA8);
            }
        }

        m_va->use();
        m_shader->use();
        glDrawArrays(t_type, t_s, t_c);
    }

    void Renderer::drawInstanced(Iru::Polygon t_type, int t_s, int t_c, int t_ic) {
        if (m_shader == nullptr || m_va == nullptr)
            return;

        for (int i = 0; i < 16; i++) {
            if (m_texture[i] != nullptr) {
                glBindTextureUnit(i, m_texture[i]->m_id);
                //glBindImageTexture(0, m_texture[i]->m_id, 0, false, 0, GL_READ_ONLY, GL_RGBA8);
            }
        }

        m_va->use();
        m_shader->use();

        glDrawArraysInstanced(t_type, t_s, t_c, t_ic);
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