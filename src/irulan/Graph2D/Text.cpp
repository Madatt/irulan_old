//
// Created by Madatt on 12.11.2019.
//

#include "Graph2D/Text.h"

namespace Iru {
    Text::Text(BitmapFont &t_font, std::string t_text)
            : m_font(&t_font), m_text(t_text) {
        construct();
    }

    Text::Text(BitmapFont &t_font)
            : m_font(&t_font) {

    }

    void Text::construct() {
        m_vers.clear();

        float x = m_font->m_cell.w;
        float y = m_font->m_cell.h;
        float w = 1;
        float h = m_font->m_aspect;

        int c = 0;
        for(char a : m_text)
        {
            /*m_vers.emplace_back(Vector3(0 + c*w, 0, 0), Vector3(0 + x * float(a) + x, 1 - y * float(a), 0));
            m_vers.emplace_back(Vector3(0 + c*w, 0, 0), Vector3(0 + x * float(a) + x, 1 - y * float(a), 0));
            m_vers.emplace_back(Vector3(0 + c*w, 0, 0), Vector3(0 + x * float(a) + x, 1 - y * float(a), 0));
            m_vers.push_back(0 + c * w);
            m_vers.push_back(0);

            m_vers.push_back(1 + c * w);
            m_vers.push_back(0);

            m_vers.push_back(1 + c * w);
            m_vers.push_back(h);

            m_vers.push_back(0 + c * w);
            m_vers.push_back(h);


            m_vers.push_back(0 + x * float(a) + x);
            m_vers.push_back(1 - y * float(a));

            m_vers.push_back(0 + x * float(a) + x);
            m_vers.push_back(1 - y * float(a) - y);

            m_vers.push_back(0 + x * float(a));
            m_vers.push_back(1 - y * float(a) - y);

            c++;*/
        }
    }
}