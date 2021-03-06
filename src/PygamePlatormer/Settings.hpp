#pragma once

#include <array>
#include <string_view>

// clang-format off
constexpr std::array<std::string_view, 11> LEVEL_MAP = {
    "                            ",
    "                            ",
    "                            ",
    " XX    XXX            XX    ",
    " XX P                       ",
    " XXXX         XX        XX  ",
    " XXXX       XX              ",
    " XX    X  XXXX    XX  XX    ",
    "       X  XXXX    XX  XXX   ",
    "    XXXX  XXXXXX  XX  XXXX  ",
    "XXXXXXXX  XXXXXX  XX  XXXX  ",
};
// clang-format on

constexpr int TILE_SIZE = 64;

constexpr int SCREEN_WIDTH = 1200;
constexpr int SCREEN_HEIGHT = static_cast<int>(LEVEL_MAP.size() * TILE_SIZE);
