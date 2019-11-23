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

namespace Iru {
    RenderTarget::RenderTarget(const Vector2i &t_viewport)
            : m_viewport(t_viewport), m_ort(Matrix::createOrtho(t_viewport.x, t_viewport.y, 1.f, -1.f)) {

    }

    void RenderTarget::setVA(const VertexArray &t_va) {
        m_va = &t_va;
    }

    void RenderTarget::setShader(const Shader &t_sha) {
        m_shader = &t_sha;
    }

    void RenderTarget::setTexture(const Texture &t_tex, int t_n) {
        m_texture[t_n] = &t_tex;
    }

    void RenderTarget::render(Polygon t_type, int t_s, int t_c) {
        use();

        if (m_shader == nullptr || m_va == nullptr)
            return;

        for (int i = 0; i < 16; i++) {
            if (m_texture[i] != nullptr) {
                glBindTextureUnit(i, m_texture[i]->m_id);
            }
        }

        glBindVertexArray(m_va->m_id);
        glUseProgram(m_shader->m_id);
        glDrawArrays(t_type, t_s, t_c);
    }

    void RenderTarget::renderIndexed(Polygon t_type, int t_c, unsigned int t_offset) {
        use();

        if (m_shader == nullptr || m_va == nullptr)
            return;

        for (int i = 0; i < 16; i++) {
            if (m_texture[i] != nullptr) {
                glBindTextureUnit(i, m_texture[i]->m_id);
            }
        }

        glBindVertexArray(m_va->m_id);
        glUseProgram(m_shader->m_id);
        glDrawElements(t_type, t_c, GL_UNSIGNED_BYTE, (void *) t_offset);
    }

    void RenderTarget::renderInstanced(Polygon t_type, int t_s, int t_c, int t_ic) {
        use();

        if (m_shader == nullptr || m_va == nullptr)
            return;

        for (int i = 0; i < 16; i++) {
            if (m_texture[i] != nullptr) {
                glBindTextureUnit(i, m_texture[i]->m_id);
            }
        }


        glBindVertexArray(m_va->m_id);
        glUseProgram(m_shader->m_id);
        glDrawArraysInstanced(t_type, t_s, t_c, t_ic);
    }

    void RenderTarget::render(Drawable &t_ob) {
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