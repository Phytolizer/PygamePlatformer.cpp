#pragma once

#include "Player.hpp"
#include "Settings.hpp"
#include "Tile.hpp"

#include <memory>
#include <string_view>
#include <vector>

class Level
{
    const wrapsdl::Texture* m_texture;
    std::vector<Tile> m_tiles;
    int m_worldShift;
    std::unique_ptr<Player> m_player;

    template <size_t Height>
    void setupLevel(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& layout);

  public:
    template <size_t Height>
    Level(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& levelData,
          const wrapsdl::Texture* texture = nullptr);
    void run(const wrapsdl::Renderer& renderer, const std::array<bool, SDL_NUM_SCANCODES>& keysPressed);
};

template <size_t Height>
void Level::setupLevel(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& layout)
{
    for (size_t i = 0; i < Height; ++i)
    {
        std::string_view row = layout[i];
        for (size_t j = 0; j < row.size(); ++j)
        {
            const float x = static_cast<float>(j * TILE_SIZE);
            const float y = static_cast<float>(i * TILE_SIZE);
            switch (row[j])
            {
            case 'X':
                m_tiles.emplace_back(renderer, glm::vec2{x, y}, static_cast<float>(TILE_SIZE));
                break;
            case 'P':
                m_player = std::make_unique<Player>(renderer, glm::vec2{x, y});
                break;
            default:
                break;
            }
        }
    }
}

template <size_t Height>
Level::Level(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& levelData,
             const wrapsdl::Texture* texture)
    : m_texture{texture}, m_worldShift{0}
{
    setupLevel(renderer, levelData);
}
