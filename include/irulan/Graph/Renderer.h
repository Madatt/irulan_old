//
// Created by Dawid on 05.09.2019.
//

#ifndef RSMOL_RENDERER_H
#define RSMOL_RENDERER_H

#include <string>
#include "Defines.h"

namespace Iru {
    class Game;
    class VertexArray;
    class Shader;
    class Texture;


    class Renderer {
    public:
        Renderer();
        ~Renderer() = default;

        void setVA(VertexArray *t_va);
        void setShader(Shader *t_sha);
        void setTexture(Texture *t_tex, int t_n);

        void drawArrays(Polygon t_type, int t_s, int t_c);
        //void drawMesh(Mesh &t_mesh);

        void flush();
        void clear();
    private:
        VertexArray *m_va = nullptr;
        Shader *m_shader = nullptr;
        Texture *m_texture[16]{};

        bool m_ok = 0;
    };
}
#endif //RSMOL_RENDERER_H
