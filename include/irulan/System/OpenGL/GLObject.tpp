//
// Created by Madatt on 27.11.2019.
//

#include "GLObject.h"
#include <iostream>


namespace Iru {
    template<typename T>
    GLObject<T>::GLObject() {
        m_rc = new RefCounter();
        m_id = T::create();
    }


    template<typename T>
    GLObject<T>::GLObject(const GLObject<T> &t_glo) {
        t_glo.m_rc->incr();
        m_rc = t_glo.m_rc;
        m_id = t_glo.m_id;

    }

    template<typename T>
    GLObject<T>::GLObject(const unsigned int &t_id) {
        m_rc = new RefCounter();
        m_id = t_id;
    }

    template<typename T>
    GLObject<T>::~GLObject() {
        m_rc->decr();

        if(m_rc->get() <= 0)
        {
            //std::cout << "Deleted" << std::endl;
            delete m_rc;
            T::release(m_id);
        }
    }


    template<typename T>
    GLObject<T> &GLObject<T>::operator=(const GLObject<T> &t_glo) {
        m_rc->decr();

        if(m_rc->get() <= 0)
        {
            delete m_rc;
            T::release(m_id);
        }

        t_glo.m_rc->incr();
        m_rc = t_glo.m_rc;
        m_id = t_glo.m_id;

        return *this;
    }
}