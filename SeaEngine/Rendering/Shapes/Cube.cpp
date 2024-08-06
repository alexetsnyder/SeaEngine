#include "Cube.h"

namespace SeaEngine
{
	float cubeVertices[120]
	{
		//Front Face
		 0.5f,  0.5f,  0.5f,   1.0f, 1.0f,	//top right
		-0.5f,  0.5f,  0.5f,   0.0f, 1.0f,	//top left
		 0.5f, -0.5f,  0.5f,   1.0f, 0.0f,	//bottom right
		-0.5f, -0.5f,  0.5f,   0.0f, 0.0f,	//bottom left

		//Back Face
		-0.5f,  0.5f,  -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f,  -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f,  -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  -0.5f,  1.0f, 0.0f,

		//Top Face
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

		//Bottom Face
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 0.0f,

		//Left Face
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		//Right Face
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	};

	float cubeIndices[36]
	{
		 0,  1,  2,  2,  1,  3, //Front Face
		 4,  5,  6,  6,  5,  7, //Back Face
		 8,  9, 10, 10,  9, 11, //Top Face
		12, 13, 14, 14, 13, 15, //Bottom Face
		16, 17, 18, 18, 17, 19, //Left Face
		20, 21, 22, 22, 21, 23, //Right Face

	};

	Cube::Cube(IRenderer* renderer)
		: renderer_{ renderer }
	{
		Mesh mesh{};
		for (int v = 0; v < 120; v += 5)
		{
			mesh.addVertex(
				Vertex{
					{ cubeVertices[v], cubeVertices[v + 1], cubeVertices[v + 2]},
					{ cubeVertices[v + 3], cubeVertices[v + 4] }
				}
			);
		}

		for (int i = 0; i < 36; i++)
		{
			mesh.addIndex(cubeIndices[i]);
		}

		renderer->sendData(mesh);
	}
}