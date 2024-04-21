#pragma once

#include "MeshRenderer.h"

namespace SeaEngine
{
	class QuadMesh
	{
		public:
			QuadMesh();
			~QuadMesh();

			const MeshRenderer* renderer() const;

		private:
			MeshRenderer* meshRenderer_;
	};
}
