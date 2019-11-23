//
// Created by Madatt on 12.11.2019.
//

#include "Graph2D/Font/Text.h"
#include "App.h"
#include <string>
#include <iostream>

namespace Iru {
    Text::Text(const BitmapFont &t_font, std::string t_text)
            : m_font(&t_font), m_text(t_text) {
        m_quads.setTexture(*t_font.m_tex);
        construct();
    }

    Text::Text(const BitmapFont &t_font)
            : m_font(&t_font) {
        m_quads.setTexture(*t_font.m_tex);
    }

    void Text::construct() {
        m_quads.clear();

        float x = m_font->m_cell.w;
        float y = m_font->m_cell.h;
        float w = m_font->m_cell.x;
        float h = m_font->m_cell.y;
        int xx = 0;
        int yy = 0;
        float c = 0;

        for (char a : m_text) {
            a -= 32;
            yy = ((int)a / m_font->m_columns) + 1;
            xx = ((int)a % m_font->m_columns) ;

            std::cout << xx << " " << yy << std::endl;

            m_quads.add(
                    Rect(w * c, 0, w, h),
                    //Rect( (float) xx * x, (float) (m_font->m_rows - yy - 1) * y, x, y)
                    Rect(3*x, -y, x, y)
                    );
            c++;
        }

    }


    void Text::draw(RenderTarget &t_ren) {
        m_quads.draw(t_ren);
    }
}