#pragma once
#include "SmartTexture.hpp"

namespace wrapsdl
{
class Sprite
{
    SmartTexture m_texture;
    SDL_Rect m_rect;

  public:
    explicit Sprite(SmartTexture tex);
    const SmartTexture& getTexture() const;
    const SDL_Rect& getRect() const;
    void setTopLeft(int x, int y);
    void setMidBottom(int x, int y);
    void setCenter(int x, int y);
    bool collides(const Sprite& other) const;
    bool collides(const SDL_Point& pt) const;
};
} // namespace wrapsdl
