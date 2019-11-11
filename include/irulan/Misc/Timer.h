//
// Created by Madatt on 11.11.2019.
//

#ifndef IRULAN_TIMER_H
#define IRULAN_TIMER_H

namespace Iru {
    class Timer {
    public:
        Timer();
        virtual ~Timer() = 0;

        unsigned int reset();
        unsigned int getElapsed();

    private:
        unsigned int m_ticks;
    };
}


#endif //IRULAN_TIMER_H
