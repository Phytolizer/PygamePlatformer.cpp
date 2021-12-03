#pragma once

#include <array>
#include <wrapsdl/Sprite.hpp>

class Player : public wrapsdl::Sprite
{
    glm::vec2 m_direction;
    void getInput(const std::array<bool, SDL_NUM_SCANCODES>& keysPressed);
    static constexpr float SPEED = 8.0f;

  public:
    Player(const wrapsdl::Renderer& renderer, const glm::vec2& pos);
    void update(const std::array<bool, SDL_NUM_SCANCODES>& keysPressed);
};
