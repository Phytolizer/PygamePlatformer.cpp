#include "wrapsdl/Renderer.hpp"

#include "wrapsdl/Core.hpp"
#include "wrapsdl/Sprite.hpp"
#include "wrapsdl/Texture.hpp"

void wrapsdl::Renderer::cleanup() const
{
    if (m_renderer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer);
    }
}

wrapsdl::Renderer::Renderer(const Window& window, const int index, const Uint32 flags)
    : m_renderer(CheckPointer(SDL_CreateRenderer(window.get(), index, flags)))
{
}

wrapsdl::Renderer::~Renderer()
{
    cleanup();
}

wrapsdl::Renderer::Renderer(Renderer&& other) noexcept : m_renderer(other.m_renderer)
{
    other.m_renderer = nullptr;
}

wrapsdl::Renderer& wrapsdl::Renderer::operator=(Renderer&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_renderer = other.m_renderer;
        other.m_renderer = nullptr;
    }
    return *this;
}

SDL_Renderer* wrapsdl::Renderer::get() const
{
    return m_renderer;
}

void wrapsdl::Renderer::setDrawBlendMode(const SDL_BlendMode bm) const
{
    CheckCode(SDL_SetRenderDrawBlendMode(m_renderer, bm));
}

void wrapsdl::Renderer::setDrawColor(const SDL_Color color) const
{
    CheckCode(SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a));
}

void wrapsdl::Renderer::clear() const
{
    CheckCode(SDL_RenderClear(m_renderer));
}

void wrapsdl::Renderer::clearWith(const SDL_Color color) const
{
    setDrawColor(color);
    clear();
}

void wrapsdl::Renderer::present() const
{
    SDL_RenderPresent(m_renderer);
}

void wrapsdl::Renderer::copy(const Texture& texture, const SDL_Rect* src, const SDL_FRect* dst) const
{
    CheckCode(SDL_RenderCopyF(m_renderer, texture.get(), src, dst));
}

void wrapsdl::Renderer::copy(const Sprite& spr) const
{
    const SDL_FRect r = spr.getRect();
    copy(spr.getTexture(), nullptr, &r);
}

void wrapsdl::Renderer::setTarget(const Texture& target) const
{
    CheckCode(SDL_SetRenderTarget(m_renderer, target.get()));
}

void wrapsdl::Renderer::resetTarget() const
{
    CheckCode(SDL_SetRenderTarget(m_renderer, nullptr));
}

void wrapsdl::Renderer::fillRect(const SDL_Rect rect) const
{
    CheckCode(SDL_RenderFillRect(m_renderer, &rect));
}
