#include "System/Logging/ErrorLog.h"
#include "Rendering/Shader.h"
#include "Rendering/Mesh/MeshRenderer.h"
#include "Rendering/Shapes/Quad.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
	int width = 800;
	int height = 600;

	sf::Window window{ sf::VideoMode(width, height), "SeaEngine" };
	window.setVerticalSyncEnabled(true);

	window.setActive(true);

	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(sf::Context::getFunction)))
	{
		SeaEngine::Sys::ErrorLog::log("gladLoadGLLoader(GLADloadproc)", "GLAD load failed.");
		return EXIT_FAILURE;
	}

	glViewport(0, 0, width, height);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	SeaEngine::Shader shader{};
	if (!shader.setVertexShader("Rendering/Shaders/basic.vert") ||
		!shader.setFragmentShader("Rendering/Shaders/basic.frag") ||
		!shader.compile() ||
		!shader.link())
	{
		SeaEngine::Sys::ErrorLog::log("Main::CreateShader", "Could not create Shaders");
		return EXIT_FAILURE;
	}

	SeaEngine::MeshRenderer meshRenderer{};
	SeaEngine::Quad quad{ &meshRenderer };

	sf::Texture texture{};
	texture.loadFromFile("Assets/Textures/stone.png");
	texture.generateMipmap();

	bool isRunning = true;
	while (isRunning)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}

			glClear(GL_COLOR_BUFFER_BIT);

			shader.use();

			//glm::perspective(glm::radians(45.0f), static_cast<float>(width) / height, 0.1f, 1000.0f)

			glm::mat4 projection{ 1.0f };
			glm::mat4 view{ 1.0f };
			glm::mat4 model{ 1.0f };

			shader.setUniform("projection", projection);
			shader.setUniform("view", view);
			shader.setUniform("model", model);

			sf::Texture::bind(&texture);

			quad.renderer()->draw(shader);

			window.display();
		}
	}

	return EXIT_SUCCESS;
}