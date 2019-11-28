//
// Created by Madatt on 19.09.2019.
//

#ifndef RSMOL_TEXTURE2D_H
#define RSMOL_TEXTURE2D_H

#include "irulan/System/Defines.h"
#include "Math/Vector2.h"
#include "System/OpenGL/GLObject.h"
#include "System/Resources/Resource.h"
#include <string>

namespace Iru {
    struct Image{
        int width;
        int height;
        unsigned char* data;
    };



    class Texture2D : public Resource{
        friend class RenderTarget;

    public:
        Texture2D();
        Texture2D(Image t_img);
        Texture2D(int t_w, int t_h);
        ~Texture2D() = default;

        void setData(int t_x, int t_y, int t_w, int t_h, Format t_f, void *data);

        static Texture2D _loadBMP(std::string t_path);

        Vector2i getSize() const {return m_size;};

        void create(int t_w, int t_h);

    private:
        GLObject<GLTexture> m_ptr;

        Vector2i m_size;
    };
}

#endif //RSMOL_TEXTURE2D_H
