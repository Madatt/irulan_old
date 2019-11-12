//
// Created by Madatt on 12.11.2019.
//

#include "Graph2D/BitmapFont.h"

namespace IruE {
    BitmapFont::BitmapFont(Iru::Texture2D &t_tex, int t_r, int t_c) {
        setTexture(t_tex, t_r, t_c);
    }

    void BitmapFont::setTexture(Iru::Texture2D &t_tex, int t_r, int t_c) {
        m_tex = &t_tex;
        m_rows = t_r;
        m_columns = t_c;

        m_chars = m_rows * m_columns;
        float x = (float) t_tex.getWidth() / (float) t_c;
        float y = (float) t_tex.getHeight() / (float) t_r;
        m_aspect = y / x;
        m_cell = Iru::Rect(0, 0, x, y);
    }
}