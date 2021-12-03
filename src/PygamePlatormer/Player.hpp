#pragma once

#include <array>
#include <wrapsdl/Sprite.hpp>

class Player : public wrapsdl::Sprite
{
    glm::vec2 m_direction;
    float m_speed;
    float m_gravity;
    float m_jumpSpeed;
    bool m_grounded;

    void getInput(const std::array<bool, SDL_NUM_SCANCODES>& keysPressed);
    void jump();

  public:
    Player(const wrapsdl::Renderer& renderer, const glm::vec2& pos);
    void update(const std::array<bool, SDL_NUM_SCANCODES>& keysPressed);
    [[nodiscard]] glm::vec2 getDirection() const;
    void setSpeed(float speed);
    [[nodiscard]] float getSpeed() const;
    void applyGravity(float dt);
    void setDirectionY(float y);
    void setGrounded();
};
