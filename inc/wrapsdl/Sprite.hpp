#pragma once
#include "Texture.hpp"

namespace wrapsdl
{
class Sprite
{
    Texture m_texture;
    SDL_Rect m_rect;

  public:
    explicit Sprite(Texture tex);
    const Texture& getTexture() const;
    const SDL_Rect& getRect() const;
    void setTopLeft(int x, int y);
    void setMidBottom(int x, int y);
    void setCenter(int x, int y);
    bool collides(const Sprite& other) const;
    bool collides(const SDL_Point& pt) const;
};
} // namespace wrapsdl
