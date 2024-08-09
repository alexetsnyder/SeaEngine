#pragma once

#include "Rendering/IRenderer.h"

namespace SeaEngine
{
	class Quad
	{
		public:
			Quad(IRenderer* renderer);
			~Quad() {}
			Quad(const Quad&) = delete;

			const IRenderer* renderer() const { return renderer_; }

		private:
			IRenderer* renderer_;
	};
}
