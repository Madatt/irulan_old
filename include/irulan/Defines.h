//
// Created by Dawid on 29.08.2019.
//

#ifndef RSMOL_DEFINES_H
#define RSMOL_DEFINES_H

#include "glad/glad.h"

namespace Iru {

    enum Type {
        FLOAT = GL_FLOAT,
        DOUBLE = GL_DOUBLE,
        U_BYTE = GL_UNSIGNED_BYTE,
    };

    enum Polygon {
        TRIANGLES = GL_TRIANGLES,
    };

    enum Format {
        RGB = GL_RGB,
        BGR = GL_BGR,
    };

    enum Filtering {
        NEAREST = GL_NEAREST,
    };
}

#endif //RSMOL_DEFINES_H
