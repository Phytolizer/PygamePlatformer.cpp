#include "Player.hpp"

Player::Player(const wrapsdl::Renderer& renderer, const glm::vec2& pos)
    : Sprite(wrapsdl::Texture{renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 32, 64})
{
    renderer.setTarget(m_texture);
    renderer.setDrawColor({255, 0, 0, 255});
    renderer.clear();
    renderer.resetTarget();
    setTopLeft(pos);
}
