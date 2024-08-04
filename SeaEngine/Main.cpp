#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
	sf::RenderWindow window{ sf::VideoMode(200, 200), "SeaEngine" };
	sf::CircleShape circle{ 100.0f };
	circle.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			window.clear();
			window.draw(circle);
			window.display();
		}
	}

	return EXIT_SUCCESS;
}