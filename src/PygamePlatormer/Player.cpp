#include "Player.hpp"

Player::Player(const wrapsdl::Renderer& renderer, const glm::vec2& pos)
    : Sprite(wrapsdl::Texture{renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 32, 64}),
      m_direction{0, 0}, m_speed{8}
{
    renderer.setTarget(m_texture);
    renderer.setDrawColor({255, 0, 0, 255});
    renderer.clear();
    renderer.resetTarget();
    setTopLeft(pos);
}

void Player::update(const std::array<bool, SDL_NUM_SCANCODES>& keysPressed)
{
    getInput(keysPressed);
    m_pos += m_direction * m_speed;
}

glm::vec2 Player::getDirection() const
{
    return m_direction;
}

void Player::setSpeed(float speed)
{
    m_speed = speed;
}

void Player::getInput(const std::array<bool, SDL_NUM_SCANCODES>& keysPressed)
{
    if (keysPressed[SDL_SCANCODE_RIGHT])
    {
        m_direction.x = 1;
    }
    else if (keysPressed[SDL_SCANCODE_LEFT])
    {
        m_direction.x = -1;
    }
    else
    {
        m_direction.x = 0;
    }
}
