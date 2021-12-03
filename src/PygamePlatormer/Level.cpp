#include "Level.hpp"

void Level::run(const wrapsdl::Renderer& renderer) const
{
	for (const auto& tile : m_tiles)
	{
	    renderer.copy(tile);
	}
}
