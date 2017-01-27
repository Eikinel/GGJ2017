#include <iostream>
#include "Screen.h"
#include "Collider.h"
#include "Button.h"


//CONSTRUCTORS
IScreen::IScreen(sf::RenderWindow& window) : _window(window)
{
}

MenuScreen::MenuScreen(sf::RenderWindow& window) : IScreen(window)
{
	this->_index = MENU_INDEX;
	this->_window.setFramerateLimit(120);
	this->_events.push_back(new WindowDefaultEvent); // Event handler for options, close window, etc.
	this->_events.push_back(new MenuEvent); // Update menu, draw it and react in terms of user inputs.

	this->_buttons.push_back(new Button("New Game", this->_window.getSize().y / 8.f, sf::Vector2f(
		this->_window.getSize().x / 1.55f,
		this->_window.getSize().y / 4.f), RIGHT));
	this->_buttons.push_back(new Button("Options", this->_window.getSize().y / 8.f, sf::Vector2f(
		this->_window.getSize().x / 1.55f,
		this->_window.getSize().y / 2.f), RIGHT));
	this->_buttons.push_back(new Button("Exit", this->_window.getSize().y / 16.f, sf::Vector2f(
		this->_window.getSize().x / 1.55f,
		this->_window.getSize().y / 1.25f), RIGHT));
	this->_buttons.push_back(new Button("Toggle bounding boxes", this->_window.getSize().y / 25.f, sf::Vector2f(
		this->_window.getSize().x / 100.f,
		this->_window.getSize().y - this->_window.getSize().y / 25.f), LEFT));
	this->_buttons[0]->onClick(&MenuEvent::createGame, static_cast<MenuEvent *>(this->_events[1]), GAME_INDEX, &this->_window);
	this->_buttons[1]->onClick(&IEvent::changeScreen, this->_events[1], OPTIONS_INDEX);
	this->_buttons[2]->onClick(&IEvent::changeScreen, this->_events[1], CLOSE);
	this->_buttons[3]->onClick(&MenuEvent::toggleBoundingBoxes, static_cast<MenuEvent *>(this->_events[1]), (int)this->_index);
}

GameScreen::GameScreen(sf::RenderWindow& window) :  IScreen(window)
{
	this->_index = GAME_INDEX;
	this->_window.setFramerateLimit(120);
	this->_events.push_back(new WindowDefaultEvent); // Event handler for options, close window, etc.
	this->_events.push_back(new GameEvent); // Update menu, draw it and react in terms of user inputs.
}

IScreen::~IScreen()
{
	std::cout << "Deleting window events" << std::endl;
	for (std::vector<IEvent *>::const_iterator it = this->_events.begin(); it != this->_events.end(); ++it)
		delete(*it);
}

MenuScreen::~MenuScreen()
{
	std::cout << "Deleting Menu Screen" << std::endl;
	for (std::vector<Button *>::const_iterator it = this->_buttons.begin(); it != this->_buttons.end(); ++it)
		delete (*it);
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

std::vector<Button *>&	MenuScreen::getButtons()
{
	return (this->_buttons);
}


//METHODS
int		IScreen::run()
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
		(*it)->draw(*this);
	this->_window.display();

	return (this->_index);
}