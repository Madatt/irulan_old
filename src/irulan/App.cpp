//
// Created by Dawid on 15.08.2019.
//

#include "App.h"
#include "glad.h"
#include <iostream>

namespace Iru {
    App::App()
            : renderer() {

    }

    void App::init() {
        if (m_init)
            return;

        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

        m_window = SDL_CreateWindow("Smol",
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    m_width, m_height,
                                    SDL_WINDOW_OPENGL);
        m_context = SDL_GL_CreateContext(m_window);
        if (m_context == nullptr) {
            close();
            return;
        }

        if (!gladLoadGL()) {
            close();
            return;
        }

        glViewport(0, 0, m_width, m_height);
        m_init = true;
    }


    int App::run() {
        init();

        while (!m_close) {
            unsigned int ela = SDL_GetTicks() - m_ticks;
            m_ticks = SDL_GetTicks();
            m_accu += ela;

            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT)
                    close();

                updateMouse(event);

            }

            while (m_accu >= 1000.0 / 60.0) {
                step(1.0 / 60.0);
                m_accu -= 1000.0 / 60.0;
            }

            draw(1.0 / 60.0);
        }

        exit();
        return 0;
    }

    void App::updateMouse(SDL_Event &t_e) {
        switch (t_e.type) {
            case SDL_MOUSEMOTION:
                m_mi.x = t_e.motion.x;
                m_mi.y = t_e.motion.y;
                break;
        }
    }

    void App::setDimensions(int t_w, int t_h) {
        m_width = t_w;
        m_height = t_h;
    }

    void App::flip() {
        SDL_GL_SwapWindow(m_window);
    }

    void App::exit() {
        SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    void App::close() {
        m_close = true;
    }

    MouseInfo &App::getMouseInfo() {
        return m_mi;
    }

    void App::setMousePosition(int t_x, int t_y) {
        SDL_WarpMouseInWindow(m_window, t_x, t_y);
    }

    void App::showCursor(bool t_b) {
        SDL_ShowCursor(t_b);
    }

    bool App::check() {
        return m_init;
    }
}