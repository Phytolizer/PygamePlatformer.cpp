#include "wrapsdl/SmartRenderer.hpp"

#include "wrapsdl/Core.hpp"
#include "wrapsdl/SmartTexture.hpp"
#include "wrapsdl/Sprite.hpp"

void wrapsdl::SmartRenderer::cleanup() const
{
    if (m_renderer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer);
    }
}

wrapsdl::SmartRenderer::SmartRenderer(const SmartWindow& window, const int index, const Uint32 flags)
    : m_renderer(CheckPointer(SDL_CreateRenderer(window.get(), index, flags)))
{
}

wrapsdl::SmartRenderer::~SmartRenderer()
{
    cleanup();
}

wrapsdl::SmartRenderer::SmartRenderer(SmartRenderer&& other) noexcept : m_renderer(other.m_renderer)
{
    other.m_renderer = nullptr;
}

wrapsdl::SmartRenderer& wrapsdl::SmartRenderer::operator=(SmartRenderer&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_renderer = other.m_renderer;
        other.m_renderer = nullptr;
    }
    return *this;
}

SDL_Renderer* wrapsdl::SmartRenderer::get() const
{
    return m_renderer;
}

void wrapsdl::SmartRenderer::setDrawBlendMode(const SDL_BlendMode bm) const
{
    CheckCode(SDL_SetRenderDrawBlendMode(m_renderer, bm));
}

void wrapsdl::SmartRenderer::setDrawColor(const SDL_Color color) const
{
    CheckCode(SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a));
}

void wrapsdl::SmartRenderer::clear() const
{
    CheckCode(SDL_RenderClear(m_renderer));
}

void wrapsdl::SmartRenderer::clearWith(const SDL_Color color) const
{
    setDrawColor(color);
    clear();
}

void wrapsdl::SmartRenderer::present() const
{
    SDL_RenderPresent(m_renderer);
}

void wrapsdl::SmartRenderer::copy(const SmartTexture& texture, const SDL_Rect* src, const SDL_Rect* dst) const
{
    CheckCode(SDL_RenderCopy(m_renderer, texture.get(), src, dst));
}

void wrapsdl::SmartRenderer::copy(const Sprite& spr) const
{
    copy(spr.getTexture(), nullptr, &spr.getRect());
}

void wrapsdl::SmartRenderer::setTarget(const SmartTexture& target) const
{
    CheckCode(SDL_SetRenderTarget(m_renderer, target.get()));
}

void wrapsdl::SmartRenderer::resetTarget() const
{
    CheckCode(SDL_SetRenderTarget(m_renderer, nullptr));
}

void wrapsdl::SmartRenderer::fillRect(const SDL_Rect rect) const
{
    CheckCode(SDL_RenderFillRect(m_renderer, &rect));
}
