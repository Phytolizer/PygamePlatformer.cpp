#include "wrapsdl/Surface.hpp"

#include "wrapsdl/Core.hpp"

void wrapsdl::Surface::cleanup() const
{
    if (m_surface != nullptr)
    {
        SDL_FreeSurface(m_surface);
    }
}

wrapsdl::Surface::Surface(SDL_Surface* surf) : m_surface(CheckPointer(surf))
{
}

wrapsdl::Surface::Surface(Surface&& other) noexcept : m_surface(other.m_surface)
{
    other.m_surface = nullptr;
}

wrapsdl::Surface& wrapsdl::Surface::operator=(Surface&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_surface = other.m_surface;
        other.m_surface = nullptr;
    }

    return *this;
}

wrapsdl::Surface::~Surface()
{
    cleanup();
}

SDL_Surface* wrapsdl::Surface::get() const
{
    return m_surface;
}
