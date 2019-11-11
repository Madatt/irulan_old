//
// Created by Madatt on 19.09.2019.
//

#ifndef RSMOL_TEXTURE2D_H
#define RSMOL_TEXTURE2D_H

#include "Defines.h"

namespace Iru {
    class Texture2D : public Texture {
        friend class Renderer;

    public:
        Texture2D();
        Texture2D(Image t_img, Format t_for);
        Texture2D(int t_w, int t_h);
        Texture2D(int t_w, int t_h, Format t_f);

        void setData(int t_x, int t_y, int t_w, int t_h, Format t_f, void *data);
        void setFiltering(Filtering t_fil);
    };
}

#endif //RSMOL_TEXTURE2D_H
