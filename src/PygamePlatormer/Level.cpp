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
    scrollX();
}

void Level::scrollX()
{
    auto& player = *m_player;
    const float playerX = player.getCenter().x;
    // ReSharper disable once CppTooWideScopeInitStatement
    const float directionX = player.getDirection().x;

    if (playerX < static_cast<float>(SCREEN_WIDTH) / 4 && directionX < 0)
    {
        m_worldShift = 8;
        player.setSpeed(0);
    }
    else if (playerX > static_cast<float>(SCREEN_WIDTH) * 3 / 4 && directionX > 0)
    {
        m_worldShift = -8;
        player.setSpeed(0);
    }
    else
    {
        m_worldShift = 0;
        player.setSpeed(8);
    }
}
