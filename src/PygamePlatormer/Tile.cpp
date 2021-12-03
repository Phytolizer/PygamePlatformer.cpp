#include "Tile.hpp"

Tile::Tile(const wrapsdl::Renderer& renderer, const glm::vec2 pos, const float size)
    : Sprite(wrapsdl::Texture{renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, static_cast<int>(size),
                              static_cast<int>(size)})
{
    setTopLeft(pos);
    renderer.setTarget(m_texture);
    renderer.setDrawColor({128, 128, 128, 255});
    renderer.clear();
    renderer.resetTarget();
}
