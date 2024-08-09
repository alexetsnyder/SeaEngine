#include "Engine.h"

#include "System/Exceptions/InitException.h"
#include "System/Logging/ErrorLog.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

namespace SeaEngine
{
	Engine::Engine(const sf::ContextSettings& context, int windowWidth, int windowHeight)
		: window_{ sf::VideoMode(windowWidth, windowHeight), "SeaEngine", sf::Style::Default, context },
		  graphics_{ windowWidth, windowHeight }, clock_{}, shader_{}, meshRenderer_ {},
		  cube_{ &meshRenderer_ }, cubeTexture_{}, isRunning_{ true }
	{
		viewContextSettings();
		createShader();
		cubeTexture_.loadFromFile("Assets/Textures/Stone.png");
		cubeTexture_.generateMipmap();
	}

	void Engine::run()
	{
		clock_.restart();
		while (isRunning_)
		{
			sf::Event event;
			while (window_.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					isRunning_ = false;
				}
			}

			update();

			render();
		}
	}

	void Engine::viewContextSettings()
	{
		sf::ContextSettings settings = window_.getSettings();

		std::cout << "Depth bits:" << settings.depthBits << std::endl;
		std::cout << "Stencil bits:" << settings.stencilBits << std::endl;
		std::cout << "Antialiasing level:" << settings.antialiasingLevel << std::endl;
		std::cout << "Version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;
	}

	void Engine::createShader()
	{
		if (!shader_.setVertexShader("Rendering/Shaders/basic.vert") ||
			!shader_.setFragmentShader("Rendering/Shaders/basic.frag") ||
			!shader_.compile() ||
			!shader_.link())
		{
			Sys::ErrorLog::log("Main::CreateShader", "Could not create Shaders");
			throw Sys::InitException{ "Failed to create Shader." };
		}
	}

	void Engine::update()
	{

	}

	void Engine::render()
	{
		graphics_.clear();

		shader_.use();

		glm::mat4 projection{ glm::perspective(glm::radians(45.0f), static_cast<float>(window_.getSize().x) / window_.getSize().y, 0.1f, 1000.0f)};
		glm::mat4 view{ 1.0f };
		glm::mat4 model{ 1.0f };

		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		model = glm::rotate(model, static_cast<float>(clock_.getElapsedTime().asSeconds()), glm::vec3(0.5f, 1.0f, 0.0f));

		shader_.setUniform("projection", projection);
		shader_.setUniform("view", view);
		shader_.setUniform("model", model);

		sf::Texture::bind(&cubeTexture_);

		cube_.renderer()->draw(shader_);

		window_.display();
	}
}
