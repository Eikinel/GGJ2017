#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "Event.h"
#include "Button.h"

std::vector<IScreen *>	all_screens;

int		main()
{
	sf::RenderWindow	window(sf::VideoMode(
		sf::VideoMode::getDesktopMode().width / 1.25f, sf::VideoMode::getDesktopMode().height / 1.25f),
		"Oni Wa Soto",
		sf::Style::Close);

	// Pushing screens to the stack
	all_screens.push_back(new MenuScreen(window));

	// Run every elements in the stack. If there's no more screen left or a close request is done, break the loop.
	int status = 0;
	while ((status = all_screens[status]->run()) >= 0 && status < all_screens.size());

	for (unsigned int i = 0; i < all_screens.size(); i++)
		delete (all_screens[i]);
	return (status);
}