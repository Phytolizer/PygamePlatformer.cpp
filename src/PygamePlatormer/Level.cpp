#include "Level.hpp"

void Level::run(const wrapsdl::Renderer& renderer)
{
    for (auto& tile : m_tiles)
    {
        tile.setTopLeft(tile.getTopLeft() + glm::vec2{m_worldShift, 0});
        renderer.copy(tile);
    }
    renderer.copy(*m_player);
}
