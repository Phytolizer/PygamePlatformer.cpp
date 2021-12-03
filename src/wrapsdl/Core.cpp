#include "wrapsdl/Core.hpp"

#include <SDL_error.h>
#include <sstream>

void wrapsdl::CheckCode(const int code)
{
    if (code != 0)
    {
        std::ostringstream message;
        message << "SDL Error: " << SDL_GetError();
        throw std::runtime_error{message.str()};
    }
}
