//
// Created by Madatt on 21.11.2019.
//

#ifndef IRULAN_QUADS_H
#define IRULAN_QUADS_H

#include "Graph/VertexArray.h"
#include "Graph/VertexBuffer.h"
#include "Graph/Render/Drawable.h"
#include "Graph/Texture2D.h"

namespace Iru {
    class Quads : public Drawable {
    public:
        Quads() = default;
        virtual ~Quads() = default;

        virtual void draw(RenderTarget &t_ren) override;

        virtual void clear();
        virtual void add(Rect t_q, Rect t_tc);
        virtual void setTexture(const Texture2D &t_tex){m_tex = &t_tex;};
        virtual void setShader(const Shader &t_sh){m_sh = &t_sh;};
        virtual void setTransform(const Matrix &t_tra){m_tra = t_tra;};


    private:
        VertexArray m_va;
        VertexBuffer m_vb;
        VertexBuffer m_ib;
        const Texture2D* m_tex;
        const Shader* m_sh;

        std::vector<float> m_data;
        std::vector<unsigned char> m_ind;
        int m_count = 0;

        Matrix m_ort;
        Matrix m_tra;

        bool m_update = true;
        void updateData(Iru::RenderTarget &t_ren);
    };
}

#endif //IRULAN_QUADS_H
