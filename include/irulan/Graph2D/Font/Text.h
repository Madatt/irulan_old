//
// Created by Madatt on 12.11.2019.
//

#ifndef IRULAN_TEXT_H
#define IRULAN_TEXT_H

#include "Graph2D/Font/BitmapFont.h"
#include "Graph/Render/Drawable.h"
#include "Graph/Render/Quads.h"
#include "Graph/VertexArray.h"
#include "Graph/VertexBuffer.h"
#include <vector>

namespace Iru {
    class Text : public Drawable {
    public:
        Text() = default;
        Text(const BitmapFont& t_font, std::string t_text);
        Text(const BitmapFont& t_font);


        void setFont(const BitmapFont& t_font){m_font = &t_font;m_quads.setTexture(*t_font.m_tex);};
        void set(std::string t_text){m_text = t_text;construct();};
        void draw(RenderTarget &t_ren) override;
        void setShader(const Shader& t_sha){m_quads.setShader(t_sha);};
        void setTransform(const Matrix &t_tra){m_quads.setTransform(t_tra);};
    private:
        Quads m_quads;

        const BitmapFont* m_font;
        std::string m_text = "";

        void construct();
    };
}

#endif //IRULAN_TEXT_H
