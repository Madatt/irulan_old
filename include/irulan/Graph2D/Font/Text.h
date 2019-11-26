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
        Text();

        void setFont(const BitmapFont& t_font){m_font = &t_font;};
        void set(const std::string &t_text);
        void draw(RenderTarget &t_ren) override;
        void setShader(const Shader& t_sh){m_sh = &t_sh;};
        void setTexture(const Texture2D& t_tex){m_tex = &t_tex;};
        void setTransform(const Matrix &t_tra){m_tra = t_tra;};
    private:
        VertexArray m_va;
        VertexBuffer m_vb;
        VertexBuffer m_ib;
        const Shader* m_sh;
        const Texture2D* m_tex;

        Matrix m_ort;
        Matrix m_tra;

        std::vector<float> m_data;
        std::vector<unsigned char> m_ind;

        const BitmapFont* m_font;
        std::string m_text = "";
        int m_count = 0;
        int m_line = 0;
        int m_pos = 0;

        void construct(const std::string &t_text);
        void clear();
    };
}

#endif //IRULAN_TEXT_H
