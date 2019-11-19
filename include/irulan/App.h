//
// Created by Dawid on 15.08.2019.
//

#ifndef RSMOL_GAME_H
#define RSMOL_GAME_H

#include "SDL2/SDL.h"
#include "Graph/Render/RenderTarget.h"

namespace Iru {
    class Renderer;

    struct MouseInfo {
        int x = 0;
        int y = 0;
        unsigned int time = 0;
    };

    class App : public RenderTarget {
    public:
        App(int t_w, int t_h);
        virtual ~App() = default;

        int run();
        void exit();
        void close();
        bool check();

        MouseInfo &getMouseInfo();
        void setMousePosition(int t_x, int t_y);
        void showCursor(bool t_b);

    private:
        int m_width = 640;
        int m_height = 480;

        SDL_Window *m_window;
        SDL_GLContext m_context = nullptr;

        bool m_init = false;
        unsigned int m_ticks = 0;

        double m_accu = 0;
        bool m_close = false;
        MouseInfo m_mi;

        void updateMouse(SDL_Event &t_e);

    protected:
        virtual void init();
        virtual void draw(double t_dt) = 0;
        virtual void step(double t_dt) = 0;
        void use();
        Rect getDimensions(){ return Rect(0, 0, m_width, m_height);};
        void flip();
    };

}


#endif //RSMOL_GAME_H
