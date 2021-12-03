#include "wrapsdl/SmartWindow.hpp"

#include "wrapsdl/Core.hpp"

void wrapsdl::SmartWindow::cleanup() const
{
    if (m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
    }
}

wrapsdl::SmartWindow::SmartWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
    : m_window(CheckPointer(SDL_CreateWindow(title, x, y, w, h, flags)))
{
}

wrapsdl::SmartWindow::~SmartWindow()
{
    cleanup();
}

wrapsdl::SmartWindow::SmartWindow(SmartWindow&& other) noexcept : m_window(other.m_window)
{
    other.m_window = nullptr;
}

wrapsdl::SmartWindow& wrapsdl::SmartWindow::operator=(SmartWindow&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_window = other.m_window;
        other.m_window = nullptr;
    }

    return *this;
}

SDL_Window* wrapsdl::SmartWindow::get() const
{
    return m_window;
}
