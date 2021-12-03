#include "wrapsdl/SmartTexture.hpp"

#include "wrapsdl/Core.hpp"

void wrapsdl::SmartTexture::cleanup() const
{
    if (m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
    }
}

wrapsdl::SmartTexture::SmartTexture(const SmartRenderer& renderer, const SmartSurface surf)
    : m_texture(CheckPointer(SDL_CreateTextureFromSurface(renderer.get(), surf.get()))), m_width(surf.get()->w),
      m_height(surf.get()->h)
{
}

wrapsdl::SmartTexture::SmartTexture(const SmartRenderer& renderer, const Uint32 format, const int access,
                                    const int width, const int height)
    : m_texture(CheckPointer(SDL_CreateTexture(renderer.get(), format, access, width, height))), m_width(width),
      m_height(height)
{
}

wrapsdl::SmartTexture::SmartTexture(SmartTexture&& other) noexcept
    : m_texture(other.m_texture), m_width(other.m_width), m_height(other.m_height)
{
    other.m_texture = nullptr;
}

wrapsdl::SmartTexture& wrapsdl::SmartTexture::operator=(SmartTexture&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_texture = other.m_texture;
        m_width = other.m_width;
        m_height = other.m_height;
        other.m_texture = nullptr;
    }
    return *this;
}

wrapsdl::SmartTexture::~SmartTexture()
{
    cleanup();
}

SDL_Texture* wrapsdl::SmartTexture::get() const
{
    return m_texture;
}

int wrapsdl::SmartTexture::width() const
{
    return m_width;
}

int wrapsdl::SmartTexture::height() const
{
    return m_height;
}
