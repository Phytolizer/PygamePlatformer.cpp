#include "wrapsdl/Texture.hpp"

#include "wrapsdl/Core.hpp"

void wrapsdl::Texture::cleanup() const
{
    if (m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
    }
}

wrapsdl::Texture::Texture(const Renderer& renderer, const Surface surf)
    : m_texture(CheckPointer(SDL_CreateTextureFromSurface(renderer.get(), surf.get()))), m_width(surf.get()->w),
      m_height(surf.get()->h)
{
}

wrapsdl::Texture::Texture(const Renderer& renderer, const Uint32 format, const int access,
                                    const int width, const int height)
    : m_texture(CheckPointer(SDL_CreateTexture(renderer.get(), format, access, width, height))), m_width(width),
      m_height(height)
{
}

wrapsdl::Texture::Texture(Texture&& other) noexcept
    : m_texture(other.m_texture), m_width(other.m_width), m_height(other.m_height)
{
    other.m_texture = nullptr;
}

wrapsdl::Texture& wrapsdl::Texture::operator=(Texture&& other) noexcept
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

wrapsdl::Texture::~Texture()
{
    cleanup();
}

SDL_Texture* wrapsdl::Texture::get() const
{
    return m_texture;
}

int wrapsdl::Texture::width() const
{
    return m_width;
}

int wrapsdl::Texture::height() const
{
    return m_height;
}
