#pragma once

#include "IRenderer.h"
#include "Mesh.h"
#include "Shader.h"

#include <glad/glad.h>

namespace SeaEngine
{
	class MeshRenderer : public IRenderer
	{
		public:
			MeshRenderer(const Mesh& mesh);
			~MeshRenderer();

			void draw(const Shader& shader) const override;

		private:
			GLuint vao_;
			GLuint ebo_;
			GLuint vbo_;
			GLsizei indicesCount_;
	};
}
