#pragma once

# include "Constants.h"
# include <iostream>

class IScreen;

class				IEvent
{
public:
	IEvent() {}
	virtual ~IEvent() {}

	virtual int		update(IScreen& screen, sf::Event& event) = 0;
	virtual void	draw(sf::RenderWindow& window) = 0;
};

class				WindowDefaultEvent : public IEvent
{
public:
	WindowDefaultEvent() {}
	virtual ~WindowDefaultEvent() { std::cout << "Deleting WindowDefaultEvent" << std::endl; }

	virtual int		update(IScreen& screen, sf::Event& event);
	virtual void	draw(sf::RenderWindow& window) {}
};