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
        Texture2D();
        Texture2D(Image t_img, Format t_for);
        Texture2D(int t_w, int t_h);
        Texture2D(int t_w, int t_h, Format t_f);

        void generate();
        void setData(int t_x, int t_y, int t_w, int t_h, Format t_f, void *data);
        void setFiltering(Filtering t_fil);

        static Texture2D _loadBMP(std::string t_path);
    };
}

#endif //RSMOL_TEXTURE2D_H
