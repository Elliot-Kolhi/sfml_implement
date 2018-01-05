#include <SFML/Graphics.hpp>

#include "app.hpp"


int main()
{

	sf::RenderWindow window(sf::VideoMode(900, 700), "Q-Learning Application", sf::Style::Close);
	window.setFramerateLimit(240);

	sf::Font font;
	if (!font.loadFromFile("../res/fonts/notalot35.ttf"))
	{
		printf("ERROR: Could not load font '../res/fonts/notalot35.ttf'. Exiting the app.");
		return -9001;
	}

	App app(font);

	while (window.isOpen())
    	{

		// Poll events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
		        	window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
			    if (event.mouseButton.button == sf::Mouse::Left)
			    {
				// TEMP commented away. UNCOMMENT for debug
				/*
				std::cout << "the left button was pressed" << std::endl;
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				*/
				app.passClickEvent(sf::Vector2f(event.mouseButton.x,event.mouseButton.y));
			    }
			}
			else if (event.type == sf::Event::MouseButtonReleased) {

			    if (event.mouseButton.button == sf::Mouse::Left)
			    {
				app.passReleaseEvent(sf::Vector2f(event.mouseButton.x,event.mouseButton.y));
			    }
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				// TEMP commented away. UNCOMMENT for debug
			    //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
			    //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
				app.passMoveEvent(sf::Vector2f(event.mouseMove.x,event.mouseMove.y));
			}

		}

		// Update objects
		app.updateGame();

		// Render the objects on the screen
		window.clear();	
		app.drawObjects(window);
		window.display();
	}

	return 0;
}	
