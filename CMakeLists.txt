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
find_package(
    glm
    CONFIG
    REQUIRED
)

add_custom_target(
    "copy_assets"
    COMMAND "${CMAKE_COMMAND}" -E copy_directory "${PROJECT_SOURCE_DIR}/res"
            "${CMAKE_CURRENT_BINARY_DIR}/res"
)

add_library(
    "wrapsdl"
    "inc/wrapsdl/Core.hpp"
    "inc/wrapsdl/GraphicsContext.hpp"
    
    
    
    
    "inc/wrapsdl/Sprite.hpp"
    "src/wrapsdl/Core.cpp"
    "src/wrapsdl/GraphicsContext.cpp"
    "src/wrapsdl/Renderer.cpp"
    "src/wrapsdl/Surface.cpp"
    "src/wrapsdl/Texture.cpp"
    "src/wrapsdl/Window.cpp"
    "src/wrapsdl/Sprite.cpp"
)
target_link_libraries(
    "wrapsdl"
    PUBLIC "SDL2::SDL2-static"
           "SDL2::SDL2_image"
           "SDL2::SDL2_ttf"
           "SDL2::SDL2_mixer"
)
target_include_directories("wrapsdl" PUBLIC "inc")
target_compile_features("wrapsdl" PUBLIC "cxx_std_20")

# Add source to this project's executable.
add_executable(
    "PygamePlatformer.cpp" WIN32
    "src/PygamePlatormer/PygamePlatformer.cpp"
    "src/PygamePlatormer/Settings.hpp"
    "src/PygamePlatormer/Tile.hpp"
 "src/PygamePlatormer/Tile.cpp")
if(WIN32)
    target_link_libraries("PygamePlatformer.cpp" PRIVATE "SDL2::SDL2main")
endif()
target_link_libraries("PygamePlatformer.cpp" PRIVATE "wrapsdl" "glm::glm")
target_include_directories("PygamePlatformer.cpp" PRIVATE "inc")
target_compile_features("PygamePlatformer.cpp" PUBLIC "cxx_std_20")
add_dependencies("PygamePlatformer.cpp" "copy_assets")
