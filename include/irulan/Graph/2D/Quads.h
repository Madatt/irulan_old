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
    class App;

    class Quads : public Drawable {
    public:
        Quads(App* t_app);
        virtual ~Quads();

        void draw(RenderTarget &t_ren) override;

        int add(Rectf t_q, Rectf t_t);


        void setTexture(const Texture2D &t_tex){m_tex = &t_tex;};
        void setShader(const Shader &t_sh){m_sh = &t_sh;};
        void setTransform(const Matrix &t_tra){m_tra = t_tra;};

    protected:
        App* m_app;
        VertexArray m_va;
        Buffer* m_b_v;
        Buffer* m_b_t;
        Buffer* m_b_i;
        const Texture2D* m_tex;
        const Shader* m_sh;

        std::vector<float> m_vers;
        std::vector<float> m_texs;
        std::vector<unsigned char> m_ind;
        int m_count = 0;
        int m_max = 0;

        Matrix m_ort;
        Matrix m_tra;

    };
}

#endif //IRULAN_QUADS_H
