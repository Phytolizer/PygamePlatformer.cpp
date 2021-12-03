#include "wrapsdl/GraphicsContext.hpp"

#include "wrapsdl/Core.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

wrapsdl::GraphicsContext::GraphicsContext()
{
    CheckCode(SDL_Init(SDL_INIT_VIDEO));
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::ostringstream ss;
        ss << "IMG_Init failed: " << IMG_GetError();
        throw std::runtime_error(ss.str());
    }
    CheckCode(TTF_Init());
}

wrapsdl::GraphicsContext::~GraphicsContext()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
