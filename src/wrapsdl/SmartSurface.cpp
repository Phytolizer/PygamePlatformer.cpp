#include "wrapsdl/SmartSurface.hpp"

#include "wrapsdl/Core.hpp"

void wrapsdl::SmartSurface::cleanup() const
{
    if (m_surface != nullptr)
    {
        SDL_FreeSurface(m_surface);
    }
}

wrapsdl::SmartSurface::SmartSurface(SDL_Surface* surf) : m_surface(CheckPointer(surf))
{
}

wrapsdl::SmartSurface::SmartSurface(SmartSurface&& other) noexcept : m_surface(other.m_surface)
{
    other.m_surface = nullptr;
}

wrapsdl::SmartSurface& wrapsdl::SmartSurface::operator=(SmartSurface&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_surface = other.m_surface;
        other.m_surface = nullptr;
    }

    return *this;
}

wrapsdl::SmartSurface::~SmartSurface()
{
    cleanup();
}

SDL_Surface* wrapsdl::SmartSurface::get() const
{
    return m_surface;
}
