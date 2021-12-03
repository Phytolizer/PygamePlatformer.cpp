// PygamePlatformer.cpp.cpp : Defines the entry point for the application.
//

#include "wrapsdl/GraphicsContext.hpp"
#include "wrapsdl/SmartRenderer.hpp"
#include "wrapsdl/SmartWindow.hpp"

#include <SDL.h>

constexpr int SCREEN_WIDTH = 1200;
constexpr int SCREEN_HEIGHT = 700;

int main(int /*argc*/, char** /*argv*/)
{
    GraphicsContext context;
    const SmartWindow window{"Pygame Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                             SCREEN_WIDTH,        SCREEN_HEIGHT,           SDL_WINDOW_ALLOW_HIGHDPI};
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

        renderer.clearWith({0, 0, 0, 255});
        renderer.present();
    }

    return 0;
}
