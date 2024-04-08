#include <SDL/SDL.h>

#include <iostream>
#include <cstdlib>

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
										  SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		std::cout << "ERROR::SDL_CreateWindow(...): " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	while (pollEvents());

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
