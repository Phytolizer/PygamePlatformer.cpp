#include "wrapsdl/Window.hpp"

#include "wrapsdl/Core.hpp"

void wrapsdl::Window::cleanup() const
{
    if (m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
    }
}

wrapsdl::Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags)
    : m_window(CheckPointer(SDL_CreateWindow(title, x, y, w, h, flags)))
{
}

wrapsdl::Window::~Window()
{
    cleanup();
}

wrapsdl::Window::Window(Window&& other) noexcept : m_window(other.m_window)
{
    other.m_window = nullptr;
}

wrapsdl::Window& wrapsdl::Window::operator=(Window&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_window = other.m_window;
        other.m_window = nullptr;
    }

    return *this;
}

SDL_Window* wrapsdl::Window::get() const
{
    return m_window;
}
