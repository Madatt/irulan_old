//
// Created by Madatt on 11.11.2019.
//

#include "Misc/Timer.h"
#include "SDL2/SDL.h"

namespace Iru {
    Timer::Timer()
    :m_ticks(SDL_GetTicks()){

    }

    unsigned int Timer::reset() {
        unsigned int tmp = m_ticks;
        m_ticks = SDL_GetTicks();
        return SDL_GetTicks() - tmp;
    }

    unsigned int Timer::getElapsed() {
        return SDL_GetTicks() - m_ticks;
    }
}