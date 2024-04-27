#include "Game.h"

#include "Exceptions/InitException.h"
#include "System/Logging/ErrorLog.h"

namespace SeaEngine
{
	Game::Game(const std::string& title, int windowWidth, int windowHeight)
		: gameState_{ GameState::RUNNING }, window_{ title.c_str(), windowWidth, windowHeight },
		  shader_{}, quadMesh_{}
	{
		createShader();
	}

	Game::~Game()
	{
		
	}

	void Game::run()
	{
		loop();
	}

	void Game::createShader()
	{
		if (!shader_.setVertexShader("Rendering/Shaders/basicVertex.glsl") ||
			!shader_.setFragmentShader("Rendering/Shaders/basicFragment.glsl") ||
			!shader_.compile() ||
			!shader_.link())
		{
			SeaEngine::Sys::ErrorLog::log("Main::CreateShader", "Could not create Shaders");
			throw InitException("Shaders Failed.");
		}
	}

	void Game::pollEvents()
	{
		SDL_Event event;
		while (window_.pollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameState_ = GameState::EXIT;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					gameState_ = GameState::EXIT;
				}
				else if (event.key.keysym.sym == SDLK_F1)
				{
					window_.toggleFullScreen();
				}
				break;
			}
		}
	}

	void Game::loop()
	{
		while (gameState_ != GameState::EXIT)
		{
			pollEvents();

			window_.ClearBuffer();

			shader_.use();

			quadMesh_.renderer()->draw(shader_);

			window_.SwapBuffer();
		}
	}
}