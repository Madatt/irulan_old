//
// Created by Madatt on 12.11.2019.
//

#include "Graph/2D/Font/BitmapFont.h"

namespace Iru {
    BitmapFont::BitmapFont(const Texture2D &t_tex, int t_r, int t_c, int t_w, int t_h) {
        setTexture(t_tex, t_r, t_c, t_w, t_h);
    }

    void BitmapFont::setTexture(const Texture2D &t_tex, int t_r, int t_c, int t_w, int t_h) {
        m_tex = &t_tex;
        m_rows = t_r;
        m_columns = t_c;

        m_chars = m_rows * m_columns;
        float x = (float) t_w / (float) t_tex.getSize().x;
        float y = (float) t_h / (float) t_tex.getSize().y;
        m_aspect = (float) t_h / (float) t_w;
        m_cell = Rectf(t_w, t_h, x, y);
    }


}
