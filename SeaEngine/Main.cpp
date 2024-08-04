#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
	sf::Window window{ sf::VideoMode(200, 200), "SeaEngine" };
	window.setVerticalSyncEnabled(true);

	window.setActive(true);

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
		}
	}

	return EXIT_SUCCESS;
}