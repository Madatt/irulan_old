//
// Created by Dawid on 10.09.2019.
//

#ifndef RSMOL_TEXTURE_H
#define RSMOL_TEXTURE_H

namespace Iru {
    struct Image {
        int width;
        int height;
        unsigned char *data = nullptr;
    };


    class Texture {
        friend class Renderer;

    public:
        virtual ~Texture();

        int getWidth(){ return m_width;};
        int getHeight(){ return m_height;};

    protected:
        Texture();

        int m_width = 0;
        int m_height = 0;
        unsigned int m_id = 0;
    };
}
#endif //RSMOL_TEXTURE_H
