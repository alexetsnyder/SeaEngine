#pragma once

#include "Mesh/Mesh.h"
#include "Shader.h"

namespace SeaEngine
{
	class IRenderer
	{
		public:
			virtual ~IRenderer() {};
			virtual void sendData(const Mesh& mesh) = 0;
			virtual void draw(const Shader& shader) const = 0;
	};
}
