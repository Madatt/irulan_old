//
// Created by Madatt on 27.11.2019.
//

#ifndef IRULAN_GLTEXTURE_H
#define IRULAN_GLTEXTURE_H

#include "GLObject.h"

namespace Iru {
    class GLTexture {
    public:
        
        static unsigned int create();
        static void release(unsigned int t_id);
    };
}

#endif //IRULAN_GLTEXTURE_H
