#pragma once

#include <SDL.h>

namespace wrapsdl
{
class Surface
{
    SDL_Surface* m_surface;
    void cleanup() const;

  public:
    explicit Surface(SDL_Surface* surf);
    Surface(const Surface&) = delete;
    Surface& operator=(const Surface&) = delete;
    Surface(Surface&& other) noexcept;
    Surface& operator=(Surface&& other) noexcept;
    ~Surface();

    SDL_Surface* get() const;
};
} // namespace wrapsdl
