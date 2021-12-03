#pragma once

#include <wrapsdl/Sprite.hpp>

#include <glm/vec2.hpp>

class Tile : public wrapsdl::Sprite
{
  public:
    Tile(const wrapsdl::Renderer& renderer, glm::vec2 pos, float size);
};
