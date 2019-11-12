//
// Created by Madatt on 12.11.2019.
//

#ifndef IRULAN_BITMAPFONT_H
#define IRULAN_BITMAPFONT_H

#include "Graph/Texture2D.h"

namespace IruE {
    class BitmapFont {
    public:
        BitmapFont(Iru::Texture2D& t_tex, int t_r, int t_c);
        virtual ~BitmapFont() = default;

    private:
        int m_rows = 0;
        int m_columns = 0;

        Iru::Texture2D* m_tex = nullptr;
    };
}

#endif //IRULAN_BITMAPFONT_H
