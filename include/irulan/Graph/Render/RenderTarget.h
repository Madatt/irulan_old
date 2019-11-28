//
// Created by Madatt on 18.11.2019.
//

#ifndef IRULAN_RENDERTARGET_H
#define IRULAN_RENDERTARGET_H

#include "irulan/Misc/Rect.h"
#include "irulan/System/Defines.h"
#include "Math/Vector2.h"
#include "Math/Matrix.h"
#include "Graph/Texture2D.h"


namespace Iru{
    class VertexArray;
    class VertexBuffer;
    class Shader;
    class Drawable;

    class RenderTarget {
    public:
        RenderTarget(const Vector2i &t_viewport);
        ~RenderTarget() = default;


        void setVA(const VertexArray &t_va);
        void setShader(const Shader &t_sha);
        void setTexture(const Texture2D &t_tex, int t_n);

        void render(Polygon t_type, int t_s, int t_c);
        void renderIndexed(Polygon t_type, int t_c, unsigned int t_offset);
        void renderInstanced(Polygon t_type, int t_s, int t_c, int t_ic);
        void render(Drawable& t_ob);

        void flush();
        void clear();

        Vector2i getViewport(){ return m_viewport;};
        Matrix getOrt(){ return m_ort;};

        virtual void init() = 0;
        virtual void use() = 0;

    private:
        const VertexArray *m_va = nullptr;
        const Shader *m_shader = nullptr;
        const Texture2D *m_texture[16]{};

        Vector2i m_viewport;
        Matrix4 m_ort;

    };
}



#endif //IRULAN_RENDERTARGET_H
