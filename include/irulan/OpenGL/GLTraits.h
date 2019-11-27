//
// Created by Madatt on 27.11.2019.
//

#ifndef IRULAN_GLTRAITS_H
#define IRULAN_GLTRAITS_H

namespace Iru {
    class GLTexture {
    public:
        static unsigned int create();
        static void release(unsigned int t_id);
    };

    class GLShader {
    public:
        static unsigned int create();
        static void release(unsigned int t_id);
    };

    class GLVertexArray {
    public:
        static unsigned int create();
        static void release(unsigned int t_id);
    };

    class GLVertexBuffer {
    public:
        static unsigned int create();
        static void release(unsigned int t_id);
    };
}

#endif //IRULAN_GLTRAITS_H
