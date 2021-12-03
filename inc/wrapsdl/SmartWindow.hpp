#pragma once

#include <SDL_video.h>

namespace wrapsdl
{
class Window
{
    SDL_Window* m_window;
    void cleanup() const;

  public:
    Window(const char* title, int x, int y, int w, int h, Uint32 flags);
    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&& other) noexcept;
    Window& operator=(Window&& other) noexcept;

    SDL_Window* get() const;
};
} // namespace wrapsdl
