#pragma once

# include "Constants.h"
# include "Entity.h"
# include <iostream>

class Entity;
class IScreen;

class				IEvent
{
public:
	virtual int		update(IScreen& screen, sf::Event& event) = 0;
	virtual void	draw(IScreen& screen) = 0;
	virtual int		changeScreen(int gamestate);
};

class				WindowDefaultEvent : public IEvent
{
public:
	virtual int		update(IScreen& screen, sf::Event& event);
	virtual void	draw(IScreen& screen) {}
};

class				MenuEvent : public IEvent
{
public:
	MenuEvent();

	virtual int		update(IScreen& screen, sf::Event& event);
	virtual void	draw(IScreen& screen);

	virtual void	showBoundingBoxes(const Entity& e, sf::RenderWindow& window);
	virtual int		toggleBoundingBoxes(int gamestate);
	virtual int		createGame(int gamestate, sf::RenderWindow* window);

protected:
	bool			_toggle_bbox;
};

class				GameEvent : public IEvent
{
public:
	virtual int		update(IScreen& screen, sf::Event& event);
	virtual void	draw(IScreen& screen) {}
};