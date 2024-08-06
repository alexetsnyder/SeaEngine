#pragma once

#include "Rendering/IRenderer.h"

namespace SeaEngine
{
	class Cube
	{
		public:
			Cube(IRenderer* renderer);
			~Cube() {};
			Cube(const Cube&) = delete;

			IRenderer* renderer() { return renderer_; }

		private:
			IRenderer* renderer_;
	};
}
