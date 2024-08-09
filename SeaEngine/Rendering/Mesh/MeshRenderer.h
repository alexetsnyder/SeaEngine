#pragma once

#include "Rendering/IRenderer.h"

#include <glad/glad.h>

namespace SeaEngine
{
	class MeshRenderer : public IRenderer
	{
		public:
			MeshRenderer();
			~MeshRenderer();
			MeshRenderer(const MeshRenderer&) = delete;

			//From IRenderer
			void sendData(const Mesh& mesh) override;
			void draw(const Shader& shader) const override;

		private:
			GLuint vao_;
			GLuint ebo_;
			GLuint vbo_;
			GLsizei indicesCount_;
	};
}
