#pragma once

# include <vector>
# include "Constants.h"
# include "Event.h"

class IEvent;
class Button;

class				IScreen
{
public:
	IScreen(sf::RenderWindow& window);
	virtual ~IScreen();

	//GETTERS
	virtual sf::RenderWindow&		getWindow();
	virtual std::vector<IEvent *>&	getEvents();
	virtual unsigned int			getIndex();

	//METHODS
	virtual int	run();

protected:
	sf::RenderWindow&		_window;
	std::vector<IEvent *>	_events;
	unsigned int			_index;
};

class				MenuScreen : public IScreen
{
public:
	MenuScreen(sf::RenderWindow& window);
	virtual ~MenuScreen();

	virtual std::vector<Button *>&	getButtons();

protected:
	std::vector<Button *>	_buttons;
};

class				GameScreen : public IScreen
{
public:
	GameScreen(sf::RenderWindow& window);
	virtual ~GameScreen() {}
};