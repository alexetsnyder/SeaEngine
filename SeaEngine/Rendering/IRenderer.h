#pragma once

#include "Shader.h"

namespace SeaEngine
{
	class IRenderer
	{
		public:
			virtual ~IRenderer() {};
			virtual void draw(const Shader& shader) const = 0;
	};
}