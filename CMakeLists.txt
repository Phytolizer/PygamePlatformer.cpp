# CMakeList.txt : CMake project for PygamePlatformer.cpp, include source and
# define project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

project(
    "PygamePlatformer.cpp"
    LANGUAGES "CXX"
    VERSION "0.1.0"
    DESCRIPTION "A platformer in Pygame but actually in C++"
    HOMEPAGE_URL "https://github.com/Phytolizer/PygamePlatformer.cpp"
)

# Add source to this project's executable.
add_executable(
    PygamePlatformer.cpp WIN32
    "src/GraphicsContext.cpp"
    "src/GraphicsContext.hpp"
    "src/MySDL.cpp"
    "src/MySDL.hpp"
    "src/PygamePlatformer.cpp"
    "src/SmartRenderer.cpp"
    "src/SmartRenderer.hpp"
    "src/SmartSurface.cpp"
    "src/SmartSurface.hpp"
    "src/SmartTexture.cpp"
    "src/SmartTexture.hpp"
    "src/SmartWindow.cpp"
    "src/SmartWindow.hpp"
    "src/Sprite.cpp"
    "src/Sprite.hpp"
)

# TODO: Add tests and install targets if needed.
