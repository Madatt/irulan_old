//
// Created by Madatt on 18.11.2019.
//

#ifndef IRULAN_DRAWABLE_H
#define IRULAN_DRAWABLE_H

#include "Math/Quaternion.h"
#include "Math/Matrix.h"
#include "Graph/Render/RenderTarget.h"



namespace Iru {
    class Renderer;

    class Drawable {
        friend class Renderer;

    public:
        virtual void draw(RenderTarget &t_ren) const = 0;

        Quaternion rotation;
        Matrix position;
        Matrix scale;
    };
}

#endif //IRULAN_DRAWABLE_H
