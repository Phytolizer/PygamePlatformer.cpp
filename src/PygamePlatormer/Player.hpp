#pragma once

#include <wrapsdl/Sprite.hpp>

class Player : public wrapsdl::Sprite
{
  public:
    explicit Player(const wrapsdl::Renderer& renderer, const glm::vec2& pos);
};
