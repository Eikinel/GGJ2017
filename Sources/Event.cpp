#include "Event.h"
#include "Screen.h"

//CONSTRUCTORS


//GETTERS


//SETTERS


//METHODS
int			WindowDefaultEvent::update(IScreen& screen, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		return (CLOSE);
		break;
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			return (CLOSE);
			break;
		default:
			break;
		}
	default:
		break;
	}

	return (screen.getIndex());
}