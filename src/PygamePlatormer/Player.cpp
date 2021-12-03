#include "Player.hpp"

Player::Player(const wrapsdl::Renderer& renderer, const glm::vec2& pos)
    : Sprite(wrapsdl::Texture{renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 32, 64}),
      m_direction{0, 0}, m_speed{64}, m_gravity{32.0f}, m_jumpSpeed{-64}, m_grounded{true}
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
}

glm::vec2 Player::getDirection() const
{
    return m_direction;
}

void Player::setSpeed(const float speed)
{
    m_speed = speed;
}

float Player::getSpeed() const
{
    return m_speed;
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
    else if (keysPressed[SDL_SCANCODE_UP])
    {
        jump();
    }
    else
    {
        m_direction.x = 0;
    }
}

void Player::applyGravity(const float dt)
{
    m_direction.y += m_gravity * dt;
    m_pos.y += m_direction.y * dt;
}

void Player::setDirectionY(const float y)
{
    m_direction.y = y;
}

void Player::setGrounded()
{
    m_grounded = true;
}

void Player::jump()
{
    if (m_grounded)
    {
        m_grounded = false;
        m_direction.y = m_jumpSpeed;
    }
}
