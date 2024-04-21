#include "QuadMesh.h"

#include "Mesh.h"

namespace SeaEngine
{
	float quadVertexArray[12]
	{
		 0.5f,  0.5f,  0.0f,	//top right
		-0.5f,  0.5f,  0.0f,	//top left
		 0.5f, -0.5f,  0.0f,	//bottom right
		-0.5f, -0.5f,  0.0f,	//bottom left
	};

	int quadIndexArray[6]
	{
		0, 1, 2,
		2, 1, 3,
	};

	QuadMesh::QuadMesh()
	{
		Mesh quad{};
		for (int v = 0; v < 12; v+=3)
		{
			quad.addVertex(
				Vertex{
					{ quadVertexArray[v], quadVertexArray[v + 1], quadVertexArray[v + 2]},
					{ 0.0f, 0.0f } 
				}
			);
		}

		for (int i = 0; i < 6; i++)
		{
			quad.addIndex(quadIndexArray[i]);
		}

		meshRenderer_ = new MeshRenderer{ quad };
	}

	QuadMesh::~QuadMesh()
	{
		delete meshRenderer_;
	}

	const MeshRenderer* QuadMesh::renderer() const
	{
		return meshRenderer_;
	}
}