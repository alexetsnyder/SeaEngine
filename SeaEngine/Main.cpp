#include "Rendering/Shader.h"
#include "System/Logging/ErrorLog.h"

#include <glad/glad.h>
#include <SDL/SDL.h>

#include <iostream>
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

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "ERROR::SDL_Init(SDL_INIT_EVERYTHING): " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	SDL_Window* window = SDL_CreateWindow("SeaEngine", 
										  SDL_WINDOWPOS_CENTERED,
										  SDL_WINDOWPOS_CENTERED,
										  1024,
										  768,
										  SDL_WINDOW_OPENGL);

	if (window == nullptr)
	{
		std::cout << "ERROR::SDL_CreateWindow(...): " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	if (SDL_GL_CreateContext(window) == nullptr)
	{
		std::cout << "ERROR::SDL_GL_CreateContext(window): " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	if (!gladLoadGLLoader(static_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
	{
		std::cout << "ERROR::gladLoadGLLoader(GLADloadproc)\n";
		return EXIT_FAILURE;
	}

	glViewport(0, 0, 1024, 768);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

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
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}

bool pollEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
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
				break;
		}
	}

	return true;
}
