#include "Level.hpp"

void Level::run(const wrapsdl::Renderer& renderer, const std::array<bool, SDL_NUM_SCANCODES>& keysPressed)
{
    m_player->update(keysPressed);
    for (auto& tile : m_tiles)
    {
        tile.setTopLeft(tile.getTopLeft() + glm::vec2{m_worldShift, 0});
        renderer.copy(tile);
    }
    renderer.copy(*m_player);
}
