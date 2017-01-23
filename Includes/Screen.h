#pragma once

# include <vector>
# include "Constants.h"
# include "Event.h"

class IEvent;

class				IScreen
{
public:
	IScreen(sf::RenderWindow& window);
	virtual ~IScreen();

	virtual sf::RenderWindow&		getWindow();
	virtual std::vector<IEvent *>&	getEvents();
	virtual unsigned int			getIndex();

	virtual int	run() = 0;

protected:
	sf::RenderWindow&		_window;
	std::vector<IEvent *>	_events;
	unsigned int			_index;
};

	class				GameScreen : public IScreen
	{
	public:
		GameScreen(sf::RenderWindow& window);
		virtual ~GameScreen() {}

		virtual int	run();
	};