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

find_package(
    SDL2
    CONFIG
    REQUIRED
)
find_package(
    sdl2-image
    CONFIG
    REQUIRED
)
find_package(
    sdl2-ttf
    CONFIG
    REQUIRED
)
find_package(
    sdl2-mixer
    CONFIG
    REQUIRED
)

add_custom_target(
    "copy_assets"
    COMMAND "${CMAKE_COMMAND}" -E copy_directory "${PROJECT_SOURCE_DIR}/res"
            "${CMAKE_CURRENT_BINARY_DIR}/res"
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
target_link_libraries(
    PygamePlatformer.cpp
    PRIVATE "SDL2::SDL2-static"
            "SDL2::SDL2_image"
            "SDL2::SDL2_ttf"
            "SDL2::SDL2_mixer"
)
if(WIN32)
    target_link_libraries(PygamePlatformer.cpp PRIVATE "SDL2::SDL2main")
endif()
add_dependencies(PygamePlatformer.cpp copy_assets)

# TODO: Add tests and install targets if needed.
