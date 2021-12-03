#include "wrapsdl/Sprite.hpp"

#include <utility>

wrapsdl::Sprite::Sprite(Texture tex)
    : m_texture{std::move(tex)}, m_rect{0, 0, m_texture.width(), m_texture.height()}
{
}

const wrapsdl::Texture& wrapsdl::Sprite::getTexture() const
{
    return m_texture;
}

const SDL_Rect& wrapsdl::Sprite::getRect() const
{
    return m_rect;
}

void wrapsdl::Sprite::setTopLeft(const int x, const int y)
{
    m_rect.x = x;
    m_rect.y = y;
}

void wrapsdl::Sprite::setMidBottom(const int x, const int y)
{
    m_rect.x = x - m_rect.w / 2;
    m_rect.y = y - m_rect.h;
}

void wrapsdl::Sprite::setCenter(const int x, const int y)
{
    m_rect.x = x - m_rect.w / 2;
    m_rect.y = y - m_rect.h / 2;
}

bool wrapsdl::Sprite::collides(const Sprite& other) const
{
    return m_rect.x < other.m_rect.x + other.m_rect.w && m_rect.x + m_rect.w > other.m_rect.x &&
           m_rect.y < other.m_rect.y + other.m_rect.h && m_rect.h + m_rect.y > other.m_rect.y;
}

bool wrapsdl::Sprite::collides(const SDL_Point& pt) const
{
    return m_rect.x < pt.x && m_rect.x + m_rect.w > pt.x && m_rect.y < pt.y && m_rect.h + m_rect.y > pt.y;
}
