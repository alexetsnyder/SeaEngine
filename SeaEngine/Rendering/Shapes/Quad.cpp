#include "Quad.h"

#include "Rendering/Mesh/Mesh.h"

namespace SeaEngine
{
	float quadVertices[20]
	{
		 0.5f,  0.5f,  0.0f,  1.0f, 1.0f,	//top right
		-0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	//top left
		 0.5f, -0.5f,  0.0f,  1.0f, 0.0f,	//bottom right
		-0.5f, -0.5f,  0.0f,  0.0f, 0.0f,	//bottom left
	};

	int quadIndices[6]
	{
		0, 1, 2,
		2, 1, 3,
	};

	Quad::Quad(IRenderer* renderer)
		: renderer_{ renderer }
	{
		Mesh mesh{};
		for (int v = 0; v < 20; v += 5)
		{
			mesh.addVertex(
				Vertex{
					{ quadVertices[v], quadVertices[v + 1], quadVertices[v + 2]},
					{ quadVertices[v + 3], quadVertices[v + 4] }
				}
			);
		}

		for (int i = 0; i < 6; i++)
		{
			mesh.addIndex(quadIndices[i]);
		}

		renderer->sendData(mesh);
	}
}