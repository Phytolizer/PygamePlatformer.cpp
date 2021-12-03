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
    [[nodiscard]] float getLeft() const;
    [[nodiscard]] float getRight() const;
    [[nodiscard]] float getTop() const;
    [[nodiscard]] float getBottom() const;
    void setLeft(float left);
    void setRight(float right);
    void setTop(float top);
    void setBottom(float bottom);
    [[nodiscard]] glm::vec2 getTopLeft() const;
    [[nodiscard]] glm::vec2 getCenter() const;
    [[nodiscard]] bool collides(const Sprite& other) const;
    [[nodiscard]] bool collides(const glm::vec2& pt) const;
};
} // namespace wrapsdl
