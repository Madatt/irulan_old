//
// Created by Madatt on 12.11.2019.
//

#include "Graph/2D/Font/Text.h"
#include "irulan/System/App.h"
#include <string>
#include <iostream>

namespace Iru {
    Text::Text() {
        m_va.attachVB(m_vb, 0, 0, 4 * sizeof(float));
        m_va.attachVB(m_vb, 1, 2 * sizeof(float), 4 * sizeof(float));
        m_va.attachIB(m_ib);
        m_va.setAttrib(0, 0, 2, 0);
        m_va.setAttrib(1, 1, 2, 0);
    }

    void Text::construct(const std::string &t_text) {
        float x = m_font->m_cell.w;
        float y = m_font->m_cell.h;
        float w = m_font->m_cell.x;
        float h = m_font->m_cell.y;
        int xx = 0;
        int yy = 0;

        for (char a : t_text) {
            if (a == '\n') {
                m_pos = 0;
                m_line++;
                continue;
            }

            a -= 32;
            yy = ((int) a / m_font->m_columns) + 1;
            xx = ((int) a % m_font->m_columns);

            float x1 = w * m_pos;
            float y1 = h * m_line;
            float x2 = w * m_pos + w;
            float y2 = h * m_line + h;

            float tx1 = xx * x;
            float ty1 = -yy * y + y;
            float tx2 = xx * x + x;
            float ty2 = -yy * y;

            m_ind.push_back(0 + m_count * 4);
            m_ind.push_back(1 + m_count * 4);
            m_ind.push_back(2 + m_count * 4);
            m_ind.push_back(2 + m_count * 4);
            m_ind.push_back(3 + m_count * 4);
            m_ind.push_back(0 + m_count * 4);

            m_data.push_back(x1);
            m_data.push_back(y1);
            m_data.push_back(tx1);
            m_data.push_back(ty1);

            m_data.push_back(x1);
            m_data.push_back(y2);
            m_data.push_back(tx1);
            m_data.push_back(ty2);

            m_data.push_back(x2);
            m_data.push_back(y2);
            m_data.push_back(tx2);
            m_data.push_back(ty2);

            m_data.push_back(x2);
            m_data.push_back(y1);
            m_data.push_back(tx2);
            m_data.push_back(ty1);

            m_pos++;
            m_count++;
        }

        m_vb.setData(sizeof(float) * m_data.size(), m_data.data());
        m_ib.setData(sizeof(float) * m_ind.size(), m_ind.data());

    }

    void Text::set(const std::string &t_text) {
        if (t_text.empty()) {
            clear();
        } else if (t_text.find(m_text) == 0) {
            construct(t_text.substr(m_text.length(), t_text.length() - m_text.length()));
        } else {
            clear();
            construct(t_text);
        }

        m_text = t_text;
    }

    void Text::clear() {
        m_ind.clear();
        m_data.clear();
        m_count = 0;
        m_line = 0;
        m_pos = 0;
    }

    void Text::draw(RenderTarget &t_ren) {
        if (m_count == 0)
            return;

        m_ort = t_ren.getOrt();

        m_sh->setMatrix("u_tra", m_tra);
        m_sh->setMatrix("u_ort", m_ort);
        m_sh->setInt("u_tex", 0);
        t_ren.setTexture(*(m_font->m_tex), 0);
        t_ren.setShader(*m_sh);
        t_ren.setVA(m_va);
        t_ren.renderIndexed(Iru::TRIANGLES, m_count * 6, 0);
        t_ren.flush();
    }
}