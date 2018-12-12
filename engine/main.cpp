#include <memory>
#include <stack>
#include <utility>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "scene/title/TitleScene.hpp"

int main()
{
	// initBoostLogging();

	// Open a window.
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Nemo");
	window.setFramerateLimit(30);
	window.setKeyRepeatEnabled(false);
	// BOOST_LOG_TRIVIAL(debug) << "Window opened.";

	std::unique_ptr<nemo::Scene> scene = std::make_unique<nemo::TitleScene>();

	// Run the program as long as its window is open.
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		scene->update(window);
		window.display();

		// Check for pending events.
		if (sf::Event event;
			window.pollEvent(event))
		{
			switch (event.type) {
				// These cases apply to any state of the game.
				case sf::Event::Closed:
					// Close the window.
					// BOOST_LOG_TRIVIAL(debug) << "Window closed.";
					window.close();
					break;

				case sf::Event::LostFocus:
					// Pause the game.
					// BOOST_LOG_TRIVIAL(debug) << "Window lost focus.";
					break;

				case sf::Event::GainedFocus:
					// Resume the game.
					// BOOST_LOG_TRIVIAL(debug) << "Window gained focus.";
					break;

				default:
					// The other events depend on the current state of the game.
					break;
			}
		}
	}

	return EXIT_SUCCESS;
}