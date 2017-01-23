#include <iostream>
#include "Screen.h"


//CONSTRUCTORS
IScreen::IScreen(sf::RenderWindow& window) : _window(window)
{
}

GameScreen::GameScreen(sf::RenderWindow& window) :  IScreen(window)
{
	this->_index = GAME_INDEX;
}

IScreen::~IScreen()
{
	std::cout << "Deleting window events" << std::endl;
	for (std::vector<IEvent *>::const_iterator it = this->_events.begin(); it != this->_events.end(); ++it)
		delete(*it);
}


//GETTERS
sf::RenderWindow&		IScreen::getWindow()
{
	return (this->_window);
}

std::vector<IEvent *>&	IScreen::getEvents()
{
	return (this->_events);
}

unsigned int			IScreen::getIndex()
{
	return (this->_index);
}


//METHODS
int		GameScreen::run()
{
	int			status;
	sf::Event	event;

	while (this->_window.pollEvent(event))
	{
		for (std::vector<IEvent *>::const_iterator it = this->_events.begin(); it != this->_events.end(); ++it)
		{
			if ((status = (*it)->update(*this, event)) != this->_index)
				return (status);
		}
	}

	this->_window.clear();
	for (std::vector<IEvent *>::const_iterator it = this->_events.begin(); it != this->_events.end(); ++it)
		(*it)->draw(this->_window);
	this->_window.display();

	return (this->_index);
}