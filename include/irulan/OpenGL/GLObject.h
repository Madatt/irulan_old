//
// Created by Madatt on 27.11.2019.
//

#ifndef IRULAN_GLOBJECT_H
#define IRULAN_GLOBJECT_H

#include "OpenGL/GLTraits.h"

namespace Iru {

    template<typename T>
    class GLObject {
        class RefCounter {
            friend class GLObject;

            void incr() { m_count++; };
            void decr() { m_count--; };
            int get() { return m_count; };

            int m_count = 1;
        };

    public:
        GLObject();
        GLObject(const unsigned int &t_id);
        GLObject(const GLObject<T> &t_glo);
        ~GLObject();

        GLObject &operator=(const GLObject<T> &t_glo);

        unsigned get() const { return m_id; };
    private:
        RefCounter *m_rc = nullptr;
        unsigned int m_id = 0;
    };

}

#include "GLObject.tpp"

#endif //IRULAN_GLOBJECT_H
