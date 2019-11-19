//
// Created by Madatt on 12.11.2019.
//

#ifndef IRULAN_TEXT_H
#define IRULAN_TEXT_H

#include "Graph2D/Font/BitmapFont.h"
#include "Graph/Primitives/VertexT.h"
#include "Graph/Render/Drawable.h"
#include <vector>

namespace Iru {
    class Text : public Drawable {
    public:
        Text() = default;
        Text(BitmapFont& t_font, std::string t_text);
        Text(BitmapFont& t_font);

        void construct();
        void setFont(BitmapFont& t_font){m_font = &t_font;};
        void set(std::string t_text){m_text = t_text;};
        void draw(RenderTarget &t_ren) const override;

    protected:
        std::vector<float> m_vers;
        std::vector<int> m_charas;
        BitmapFont* m_font;
        std::string m_text = "";


        void draw(Renderer &t_ren) const;
    };
}

#endif //IRULAN_TEXT_H
