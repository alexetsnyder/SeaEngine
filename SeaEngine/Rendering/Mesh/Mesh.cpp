#include "Mesh.h"

namespace SeaEngine
{
	const std::vector<Vertex>& Mesh::vertices() const
	{
		return vertices_;
	}

	const std::vector<int>& Mesh::indices() const
	{
		return indices_;
	}

	void Mesh::addVertex(const Vertex& vertex)
	{
		vertices_.push_back(vertex);
	}

	void Mesh::addIndex(int index)
	{
		indices_.push_back(index);
	}
}