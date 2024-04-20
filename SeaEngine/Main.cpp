#include "Exceptions/InitException.h"
#include "Rendering/Shader.h"
#include "System/Logging/ErrorLog.h"
#include "System/Window.h"

#include <glad/glad.h>

#include <cstdlib>

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

bool pollEvents();

SeaEngine::Sys::Window* window;
int screenWidth{ 1024 };
int screenHeight{ 768 };

int main(int argc, char** argv)
{
	try
	{
		window = new SeaEngine::Sys::Window("SeaEngine", screenWidth, screenHeight);
	}
	catch (const SeaEngine::InitException& exception)
	{
		SeaEngine::Sys::ErrorLog::log("main", exception.what());
		return EXIT_FAILURE;
	}
	
	SeaEngine::Shader shader{};
	if (!shader.setVertexShader("Rendering/Shaders/basicVertex.glsl") ||
		!shader.setFragmentShader("Rendering/Shaders/basicFragment.glsl") ||
		!shader.compile() ||
		!shader.link())
	{
		SeaEngine::Sys::ErrorLog::log("Main::CreateShader", "Could not create Shaders");
		return EXIT_FAILURE;
	}

	GLuint vao{};
	GLuint vbo{};
	GLuint ebo{};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertexArray), quadVertexArray, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndexArray), quadIndexArray, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	while (pollEvents())
	{
		window->ClearBuffer();

		shader.use();

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		window->SwapBuffer();
	}

	delete window;

	return EXIT_SUCCESS;
}

bool pollEvents()
{
	SDL_Event event;
	while (window->pollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return false;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					return false;
				}
				else if (event.key.keysym.sym == SDLK_F1)
				{
					window->toggleFullScreen();
				}
				break;
		}
	}

	return true;
}
