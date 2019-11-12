//
// Created by Madatt on 12.11.2019.
//

#include "Graph2D/BitmapFont.h"

namespace IruE {
    BitmapFont::BitmapFont(Iru::Texture2D &t_tex, int t_r, int t_c)
    :m_tex(&t_tex), m_rows(t_r), m_columns(t_c){

    }
}