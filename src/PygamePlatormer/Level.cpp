#include "Level.hpp"

void Level::run(const wrapsdl::Renderer& renderer, const float dt, const std::array<bool, SDL_NUM_SCANCODES>& keysPressed)
{
    m_player->update(keysPressed);
    horizontalCollision(dt);
    verticalCollision(dt);
    for (auto& tile : m_tiles)
    {
        tile.setTopLeft(tile.getTopLeft() + glm::vec2{m_worldShift, 0} * dt);
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
        m_worldShift = 64;
        player.setSpeed(0);
    }
    else if (playerX > static_cast<float>(SCREEN_WIDTH) * 3 / 4 && directionX > 0)
    {
        m_worldShift = -64;
        player.setSpeed(0);
    }
    else
    {
        m_worldShift = 0;
        player.setSpeed(64);
    }
}

void Level::horizontalCollision(const float dt)
{
    m_player->setTopLeft(m_player->getTopLeft() + m_player->getDirection() * m_player->getSpeed() * dt);

    for (const auto& tile : m_tiles)
    {
        if (tile.collides(*m_player))
        {
            if (m_player->getDirection().x < 0)
            {
                m_player->setLeft(tile.getRight());
            }
            else if (m_player->getDirection().x > 0)
            {
                m_player->setRight(tile.getLeft());
            }
        }
    }
}

void Level::verticalCollision(const float dt)
{
    m_player->applyGravity(dt);

    for (const auto& tile : m_tiles)
    {
        if (tile.collides(*m_player))
        {
            if (m_player->getDirection().y > 0)
            {
                m_player->setDirectionY(0);
                m_player->setGrounded();
                m_player->setBottom(tile.getTop());
            }
            else if (m_player->getDirection().y < 0)
            {
                m_player->setTop(tile.getBottom());
            }
        }
    }
}
