// PygamePlatformer.cpp.cpp : Defines the entry point for the application.
//

#include "Settings.hpp"
#include "Tile.hpp"
#include "Level.hpp"

#include <SDL.h>
#include <wrapsdl/GraphicsContext.hpp>
#include <wrapsdl/Renderer.hpp>
#include <wrapsdl/Window.hpp>

int main(int /*argc*/, char** /*argv*/)
{
    wrapsdl::GraphicsContext context;
    const wrapsdl::Window window{"Pygame Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                 SCREEN_WIDTH,        SCREEN_HEIGHT,           SDL_WINDOW_ALLOW_HIGHDPI};
    const wrapsdl::Renderer renderer{window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};
    const Level level{renderer, LEVEL_MAP};

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
        level.run(renderer);
        renderer.present();
    }

    return 0;
}
