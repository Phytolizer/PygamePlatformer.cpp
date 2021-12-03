#pragma once

#include "Window.hpp"

#include <SDL.h>

namespace wrapsdl
{
class Texture;
class Sprite;

class Renderer
{
    SDL_Renderer* m_renderer;

    void cleanup() const;

  public:
    Renderer(const Window& window, int index, Uint32 flags);
    ~Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&& other) noexcept;
    Renderer& operator=(Renderer&& other) noexcept;

    SDL_Renderer* get() const;
    void setDrawBlendMode(SDL_BlendMode bm) const;
    void setDrawColor(SDL_Color color) const;
    void clear() const;
    void clearWith(SDL_Color color) const;
    void present() const;
    void copy(const Texture& texture, const SDL_Rect* src, const SDL_Rect* dst) const;
    void copy(const Sprite& spr) const;
    void setTarget(const Texture& target) const;
    void resetTarget() const;
    void fillRect(SDL_Rect rect) const;
};
} // namespace wrapsdl
