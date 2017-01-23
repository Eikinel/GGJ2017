#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "Event.h"

std::vector<IScreen *>	all_screens;

int		main()
{
	sf::RenderWindow	window(sf::VideoMode(
		sf::VideoMode::getDesktopMode().width / 1.25f, sf::VideoMode::getDesktopMode().height / 1.25f),
		"Oni Wa Soto",
		sf::Style::Close);
	GameScreen			game(window);

	//Set first window info
	game.getWindow().setFramerateLimit(120);
	game.getEvents().push_back(new WindowDefaultEvent); //Event handler for options, close window, etc.

	//Pushing game to the stack
	all_screens.push_back(&game);

	int status = 0;
	while ((status = all_screens[status]->run()) >= 0);

	return (status);
}