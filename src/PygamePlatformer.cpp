// PygamePlatformer.cpp.cpp : Defines the entry point for the application.
//

#include "GraphicsContext.hpp"
#include "SmartRenderer.hpp"
#include "SmartWindow.hpp"

#include <SDL.h>

int main(int /*argc*/, char** /*argv*/)
{
    GraphicsContext context;
    const SmartWindow window{"Pygame Platformer",     SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 700,
                             SDL_WINDOW_ALLOW_HIGHDPI};
    const SmartRenderer renderer{window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        renderer.clear();
        renderer.present();
    }

    return 0;
}
