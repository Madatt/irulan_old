//
// Created by Madatt on 18.11.2019.
//

#ifndef IRULAN_RENDERTARGET_H
#define IRULAN_RENDERTARGET_H

#include "irulan/Misc/Rect.h"
#include "irulan/Defines.h"
#include "Math/Matrix.h"


namespace Iru{
    class VertexArray;
    class VertexBuffer;
    class Shader;
    class Texture;
    class Drawable;

    class RenderTarget {
    public:
        RenderTarget();
        ~RenderTarget() = default;


        void setVA(VertexArray *t_va);
        void setShader(Shader *t_sha);
        void setTexture(Texture *t_tex, int t_n);

        void draw(Polygon t_type, int t_s, int t_c);
        void drawInstanced(Polygon t_type, int t_s, int t_c, int t_ic);
        void draw(Drawable& t_ob);

        void flush();
        void clear();

        virtual void init() = 0;
        virtual void use() = 0;

    private:
        VertexArray *m_va = nullptr;
        Shader *m_shader = nullptr;
        Texture *m_texture[16]{};

    };
}



#endif //IRULAN_RENDERTARGET_H
