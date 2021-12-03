// PygamePlatformer.cpp.cpp : Defines the entry point for the application.
//

#include "Settings.hpp"

#include <SDL.h>
#include <wrapsdl/GraphicsContext.hpp>
#include <wrapsdl/SmartRenderer.hpp>
#include <wrapsdl/SmartWindow.hpp>

int main(int /*argc*/, char** /*argv*/)
{
    wrapsdl::GraphicsContext context;
    const wrapsdl::SmartWindow window{"Pygame Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      SCREEN_WIDTH,        SCREEN_HEIGHT,           SDL_WINDOW_ALLOW_HIGHDPI};
    const wrapsdl::SmartRenderer renderer{window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};

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

        renderer.clearWith({0, 0, 0, 255});
        renderer.present();
    }

    return 0;
}
