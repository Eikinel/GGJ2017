#pragma once

# include "Constants.h"
# include "Entity.h"
# include "Button.h"
# include <iostream>

class IScreen;

class				IEvent
{
public:
	IEvent();
	virtual ~IEvent() {}

	virtual int		update(IScreen& screen, sf::Event& event) = 0;
	virtual void	draw(IScreen& screen) = 0;

	//GETTERS
	virtual bool				getToggleBoundingBoxes();
	virtual bool				getToggleGrid();
	virtual std::vector<bool>&	getToggleOptions();
	template <typename T> void	getBoundingBoxes(const Entity<T>& e, std::vector<sf::VertexArray>& boxes)
	{
		const sf::Color type[5] = { sf::Color::Magenta, sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::White };

		for (std::vector<T *>::const_iterator it = e.getColliders().begin(); it != e.getColliders().end(); ++it)
		{
			sf::FloatRect	box = (*it)->getShape().getGlobalBounds();
			sf::VertexArray	lines(sf::LinesStrip, 5);

			lines[0].position = sf::Vector2f(box.left, box.top);
			lines[1].position = sf::Vector2f(box.left + box.width, box.top);
			lines[2].position = sf::Vector2f(box.left + box.width, box.top + box.height);
			lines[3].position = sf::Vector2f(box.left, box.top + box.height);
			lines[4].position = sf::Vector2f(box.left, box.top);

			for (unsigned int i = 0; i < lines.getVertexCount(); i++)
				lines[i].color = type[e.getType()];
			boxes.push_back(lines);
		}
	}

	//SETTERS
	virtual	void	setToggleOptions(const std::vector<bool>& toggle_options);

	//METHODS
	virtual int	changeScreen(eGamestate gamestate, IScreen* screen);
	virtual int	createScreen(eGamestate gamestate, IScreen* screen);
	virtual int	toggleBoundingBoxes(int index);
	virtual int	toggleGrid(int index);

protected:
	std::vector<bool>	_toggle_options;
};

class				WindowDefaultEvent : public IEvent
{
public:
	WindowDefaultEvent();

	virtual int		update(IScreen& screen, sf::Event& event);
	virtual void	draw(IScreen& screen) {}
};

class				MenuEvent : public IEvent
{
public:
	MenuEvent();

	virtual int		update(IScreen& screen, sf::Event& event);
	virtual void	draw(IScreen& screen);
};

class				GameEvent : public IEvent
{
public:
	GameEvent();

	virtual int		update(IScreen& screen, sf::Event& event);
	virtual void	draw(IScreen& screen);
};