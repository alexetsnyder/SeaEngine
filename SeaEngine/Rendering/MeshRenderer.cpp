#include "MeshRenderer.h"

namespace SeaEngine
{
	MeshRenderer::MeshRenderer(const Mesh& mesh)
		: vao_{}, ebo_{}, vbo_{}, indicesCount_{}
	{
		glGenVertexArrays(1, &vao_);
		glGenBuffers(1, &vbo_);
		glGenBuffers(1, &ebo_);

		glBindVertexArray(vao_);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);

		glBufferData(GL_ARRAY_BUFFER, mesh.vertices().size() * sizeof(Vertex), &mesh.vertices().front(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinate));
		glEnableVertexAttribArray(1);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices().size() * sizeof(int), &mesh.indices().front(), GL_STATIC_DRAW);
		indicesCount_ = static_cast<GLsizei>(mesh.indices().size());

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	MeshRenderer::~MeshRenderer()
	{
		glDeleteVertexArrays(1, &vao_);
		glDeleteBuffers(1, &vbo_);
		glDeleteBuffers(1, &ebo_);
	}

	void MeshRenderer::draw(const Shader& shader) const
	{
		glBindVertexArray(vao_);
		glDrawElements(GL_TRIANGLES, indicesCount_, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}