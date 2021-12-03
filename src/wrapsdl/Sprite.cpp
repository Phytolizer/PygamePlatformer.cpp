#include "wrapsdl/Sprite.hpp"

#include <utility>

wrapsdl::Sprite::Sprite(Texture tex)
    : m_texture{std::move(tex)}, m_pos{0, 0}, m_size{m_texture.width(), m_texture.height()}
{
}

const wrapsdl::Texture& wrapsdl::Sprite::getTexture() const
{
    return m_texture;
}

SDL_FRect wrapsdl::Sprite::getRect() const
{
    return {m_pos.x, m_pos.y, m_size.x, m_size.y};
}

void wrapsdl::Sprite::setTopLeft(const glm::vec2 pos)
{
    m_pos = pos;
}

void wrapsdl::Sprite::setMidBottom(const glm::vec2 pos)
{
    m_pos.x = pos.x - m_size.x / 2;
    m_pos.y = pos.y - m_size.y;
}

void wrapsdl::Sprite::setCenter(const glm::vec2 pos)
{
    m_pos.x = pos.x - m_size.x / 2;
    m_pos.y = pos.y - m_size.y / 2;
}

glm::vec2 wrapsdl::Sprite::getTopLeft() const
{
    return m_pos;
}

glm::vec2 wrapsdl::Sprite::getCenter() const
{
    return glm::vec2{m_pos.x + m_size.x / 2, m_pos.y + m_size.y / 2};
}

bool wrapsdl::Sprite::collides(const Sprite& other) const
{
    return m_pos.x < other.m_pos.x + other.m_size.x && m_pos.x + m_size.x > other.m_pos.x &&
           m_pos.y < other.m_pos.y + other.m_size.y && m_size.y + m_pos.y > other.m_pos.y;
}

bool wrapsdl::Sprite::collides(const glm::vec2& pt) const
{
    return m_pos.x < pt.x && m_pos.x + m_size.x > pt.x && m_pos.y < pt.y && m_size.y + m_pos.y > pt.y;
}
