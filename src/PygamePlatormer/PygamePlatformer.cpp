// PygamePlatformer.cpp.cpp : Defines the entry point for the application.
//

#include "Level.hpp"
#include "Settings.hpp"

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
    Level level{renderer, LEVEL_MAP};

    std::array<bool, SDL_NUM_SCANCODES> keysPressed{false};
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
            case SDL_KEYDOWN:
                keysPressed[event.key.keysym.scancode] = true;
                break;
            case SDL_KEYUP:
                keysPressed[event.key.keysym.scancode] = false;
                break;
            default:
                break;
            }
        }

        renderer.clearWith({0, 0, 0, 255});
        level.run(renderer, keysPressed);
        renderer.present();
    }

    return 0;
}
