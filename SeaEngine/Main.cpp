#include "Exceptions/InitException.h"
#include "Rendering/QuadMesh.h"
#include "Rendering/Shader.h"
#include "System/Logging/ErrorLog.h"
#include "System/Window.h"

#include <glad/glad.h>

#include <cstdlib>

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

	SeaEngine::QuadMesh quad{};

	while (pollEvents())
	{
		window->ClearBuffer();

		shader.use();

		quad.renderer()->draw(shader);

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
