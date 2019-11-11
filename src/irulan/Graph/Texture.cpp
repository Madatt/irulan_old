
#include "Graph/Texture.h"
#include "glad/glad.h"

namespace Iru {
    Texture::Texture() {

    }

    Texture::~Texture() {
        if (m_id)
            glDeleteTextures(0, &m_id);
    }
}
