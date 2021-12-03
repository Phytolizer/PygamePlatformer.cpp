#pragma once

#include "Settings.hpp"
#include "Tile.hpp"

#include <string_view>
#include <vector>

class Level
{
    const wrapsdl::Texture* m_texture;
    std::vector<Tile> m_tiles;

    template <size_t Height>
    void setupLevel(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& layout);

  public:
    template <size_t Height>
    Level(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& levelData,
          const wrapsdl::Texture* texture = nullptr);
    void run(const wrapsdl::Renderer& renderer) const;
};

template <size_t Height>
void Level::setupLevel(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& layout)
{
    for (size_t i = 0; i < Height; ++i)
    {
        std::string_view row = layout[i];
        for (size_t j = 0; j < row.size(); ++j)
        {
            if (const char c = row[j]; c == 'X')
            {
                m_tiles.emplace_back(renderer,
                                     glm::vec2{static_cast<float>(j * TILE_SIZE), static_cast<float>(i * TILE_SIZE)},
                                     static_cast<float>(TILE_SIZE));
            }
        }
    }
}

template <size_t Height>
Level::Level(const wrapsdl::Renderer& renderer, const std::array<std::string_view, Height>& levelData,
             const wrapsdl::Texture* texture)
    : m_texture{texture}
{
    setupLevel(renderer, levelData);
}
