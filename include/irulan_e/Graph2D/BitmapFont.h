//
// Created by Madatt on 12.11.2019.
//

#ifndef IRULAN_BITMAPFONT_H
#define IRULAN_BITMAPFONT_H

#include "Graph/Texture2D.h"
#include "Misc/Rect.h"

namespace IruE {
    class BitmapFont {
        friend class Text;

    public:
        BitmapFont(Iru::Texture2D& t_tex, int t_r, int t_c);
        BitmapFont() = default;
        virtual ~BitmapFont() = default;

        void setTexture(Iru::Texture2D& t_tex, int t_r, int t_c);
    private:
        int m_rows = 0;
        int m_columns = 0;
        int m_chars = 0;
        float m_aspect = 0;
        Iru::Rect m_cell;

        Iru::Texture2D* m_tex = nullptr;
    };
}

#endif //IRULAN_BITMAPFONT_H
