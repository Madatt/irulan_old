//
// Created by Madatt on 21.11.2019.
//

#include "irulan/Graph/2D/Quads.h"
#include "Graph/Shader.h"
#include "System/App.h"

namespace Iru {
    Quads::Quads(App* t_app) {
        m_max = 25;

        m_b_v = t_app->bufferAllocator()->allocate(25 * 2 * sizeof(float) * 4);
        m_b_t = t_app->bufferAllocator()->allocate(25 * 2 * sizeof(float) * 4);
        m_b_i = t_app->bufferAllocator()->allocate(25 * 2 * sizeof(unsigned char) * 4);

        m_va.attachVB(m_b_v, 0, 0, 2 * sizeof(float));
        m_va.attachVB(m_b_t, 1, 0, 2 * sizeof(float));
        m_va.attachIB(m_b_i);
        m_va.setAttrib(0, 0, 2, 0);
        m_va.setAttrib(1, 1, 2, 0);
    }

    int Quads::add(Rectf t_q, Rectf t_t) {
        if(m_count >= m_max)
            return -1;

        m_vers.push_back(t_q.x);
        m_vers.push_back(t_q.y);
        m_vers.push_back(t_q.x);
        m_vers.push_back(t_q.y + t_q.h);
        m_vers.push_back(t_q.x + t_q.w);
        m_vers.push_back(t_q.y + t_q.h);
        m_vers.push_back(t_q.x + t_q.w);
        m_vers.push_back(t_q.y);

        m_texs.push_back(t_t.x);
        m_texs.push_back(t_t.y + t_t.h);
        m_texs.push_back(t_t.x);
        m_texs.push_back(t_t.y);
        m_texs.push_back(t_t.x + t_t.w);
        m_texs.push_back(t_t.y);
        m_texs.push_back(t_t.x + t_t.w);
        m_texs.push_back(t_t.y + t_t.h);

        m_ind.push_back(0 + m_count * 4);
        m_ind.push_back(1 + m_count * 4);
        m_ind.push_back(2 + m_count * 4);
        m_ind.push_back(2 + m_count * 4);
        m_ind.push_back(3 + m_count * 4);
        m_ind.push_back(0 + m_count * 4);



        m_b_v->setData(sizeof(float) * m_vers.size(),0 , m_vers.data());
        m_b_t->setData(sizeof(float) * m_texs.size(),0 ,m_texs.data());
        m_b_i->setData(sizeof(unsigned char) * m_ind.size(), 0, m_ind.data());
        return m_count++;
    }

    void Quads::draw(RenderTarget &t_ren) {
        m_ort = t_ren.getOrt();
        m_sh->setMatrix("u_tra", m_tra);
        m_sh->setMatrix("u_ort", m_ort);
        m_sh->setInt("u_tex", 0);
        t_ren.setTexture(*m_tex, 0);
        t_ren.setShader(*m_sh);
        t_ren.setVA(m_va);
        for(int i = 0; i < m_count; i++)
        {
            t_ren.renderIndexed(Iru::TRIANGLES, 6, i * 6 * sizeof(unsigned char));
        }

        t_ren.flush();
    }

}

