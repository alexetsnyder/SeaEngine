#pragma once

#include "Rendering/Graphics.h"
#include "Rendering/Mesh/MeshRenderer.h"
#include "Rendering/Shapes/Cube.h"
#include "Rendering/Shader.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace SeaEngine
{
	class Engine
	{
		public:
			Engine(const sf::ContextSettings& context, int windowWidth, int windowHeight);

			void run();

		private:
			void viewContextSettings();
			void createShader();
			void update();
			void render();

			bool isRunning_;
			sf::Window window_;
			Graphics graphics_;
			sf::Clock clock_;

			Shader shader_;
			MeshRenderer meshRenderer_;
			Cube cube_;
			sf::Texture cubeTexture_;
	};
}
