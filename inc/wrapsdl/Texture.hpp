#pragma once

#include "Renderer.hpp"
#include "SmartSurface.hpp"
#include <SDL.h>

namespace wrapsdl
{
class Texture
{
    SDL_Texture* m_texture;
    int m_width;
    int m_height;

    void cleanup() const;

  public:
    Texture(const Renderer& renderer, SmartSurface surf);
    Texture(const Renderer& renderer, Uint32 format, int access, int width, int height);
    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;
    Texture(Texture&& other) noexcept;
    Texture& operator=(Texture&& other) noexcept;
    ~Texture();

    SDL_Texture* get() const;
    int width() const;
    int height() const;
};
} // namespace wrapsdl
