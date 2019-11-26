//
// Created by Madatt on 21.11.2019.
//

#include "Graph/Render/Quads.h"
#include "Graph/Shader.h"

namespace Iru {
    Quads::Quads() {
        m_max = 25;

        m_va.attachVB(m_vb_v, 0, 0, 2 * sizeof(float));
        m_va.attachVB(m_vb_t, 1, 0, 2 * sizeof(float));
        m_va.attachIB(m_ib);
        m_va.setAttrib(0, 0, 2, 0);
        m_va.setAttrib(1, 1, 2, 0);
    }

    Quads::Quads(const int &t_num) :
            m_max(t_num) {

        if (m_max > 50)
            m_max = 50;

        m_va.attachVB(m_vb_v, 0, 0, 2 * sizeof(float));
        m_va.attachVB(m_vb_t, 1, 0, 2 * sizeof(float));
        m_va.attachIB(m_ib);
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



        m_vb_v.setData(sizeof(float) * m_vers.size(), m_vers.data());
        m_vb_t.setData(sizeof(float) * m_texs.size(), m_texs.data());
        m_ib.setData(sizeof(float) * m_ind.size(), m_ind.data());
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

