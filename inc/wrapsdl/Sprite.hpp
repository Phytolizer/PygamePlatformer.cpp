#pragma once
#include "Texture.hpp"

#include <glm/vec2.hpp>

namespace wrapsdl
{
class Sprite
{
  protected:
    Texture m_texture;
    glm::vec2 m_pos;
    glm::vec2 m_size;

  public:
    explicit Sprite(Texture tex);
    [[nodiscard]] const Texture& getTexture() const;
    [[nodiscard]] SDL_FRect getRect() const;
    void setTopLeft(glm::vec2 pos);
    void setMidBottom(glm::vec2 pos);
    void setCenter(glm::vec2 pos);
    [[nodiscard]] bool collides(const Sprite& other) const;
    [[nodiscard]] bool collides(const glm::vec2& pt) const;
};
} // namespace wrapsdl
