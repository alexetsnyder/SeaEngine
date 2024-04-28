#pragma once

#include "Rendering/QuadMesh.h"
#include "Rendering/Shader.h"
#include "System/Window.h"

#include <string>

namespace SeaEngine
{
	enum class GameState
	{
		RUNNING,
		EXIT,
	};

	class Game
	{
		public:
			Game(const std::string& title, int windowWidth, int windowHeight);
			~Game();

			void run();

		private:
			void createShader();
			void pollEvents();
			void loop();
			void update();
			void render();

			GameState gameState_;
			Sys::Window window_;
			Shader shader_;
			QuadMesh quadMesh_;
	};
}
