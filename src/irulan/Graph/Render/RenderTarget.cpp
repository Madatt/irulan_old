//
// Created by Madatt on 18.11.2019.
//

#include "Graph/Shader.h"
#include "Graph/VertexArray.h"
#include "Graph/VertexBuffer.h"
#include "Graph/Texture.h"
#include "Graph/Texture2D.h"
#include "Graph/Render/RenderTarget.h"
#include "Graph/Render/Drawable.h"

namespace Iru{
    RenderTarget::RenderTarget() {

    }


    void RenderTarget::setVA(VertexArray *t_va) {
        m_va = t_va;
    }

    void RenderTarget::setShader(Shader *t_sha) {
        m_shader = t_sha;
    }

    void RenderTarget::setTexture(Texture *t_tex, int t_n) {
        m_texture[t_n] = t_tex;
    }

    void RenderTarget::draw(Polygon t_type, int t_s, int t_c) {
        use();

        if (m_shader == nullptr || m_va == nullptr)
            return;

        for (int i = 0; i < 16; i++) {
            if (m_texture[i] != nullptr) {
                glBindTextureUnit(i, m_texture[i]->m_id);
            }
        }

        m_va->use();
        m_shader->use();
        glDrawArrays(t_type, t_s, t_c);
    }

    void RenderTarget::drawInstanced(Polygon t_type, int t_s, int t_c, int t_ic) {
        use();

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

    void RenderTarget::draw(Drawable &t_ob) {
        t_ob.draw(*this);
    }

    void RenderTarget::flush() {
        m_shader = nullptr;
        m_va = nullptr;

        for (int i = 0; i < 16; i++) {
            m_texture[i] = nullptr;
        }
    }

    void RenderTarget::clear() {
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        flush();
    }
}