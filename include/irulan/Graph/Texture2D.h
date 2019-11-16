//
// Created by Madatt on 19.09.2019.
//

#ifndef RSMOL_TEXTURE2D_H
#define RSMOL_TEXTURE2D_H

#include "Defines.h"
#include "Graph/Texture.h"
#include <string>

namespace Iru {
    class Texture2D : public Texture {
        friend class Renderer;

    public:
        Texture2D() = default;
        Texture2D(Texture2D& t_tex) = delete;
        Texture2D(Texture2D&& t_tex);
        Texture2D(Image t_img);
        Texture2D(int t_w, int t_h);
        ~Texture2D();

        Texture2D& operator=(const Texture2D& t_r) = delete;
        Texture2D& operator=(Texture2D&& t_r);

        void setData(int t_x, int t_y, int t_w, int t_h, Format t_f, void *data);

        static Texture2D _loadBMP(std::string t_path);

    private:
        void generate(int t_w, int t_h);
        void release();
    };
}

#endif //RSMOL_TEXTURE2D_H
