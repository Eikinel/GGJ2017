#include "Event.h"
#include "Screen.h"
#include "Button.h"
#include "Collider.h"


//CONSTRUCTORS
MenuEvent::MenuEvent()
{
	this->_toggle_bbox = false;
}


//UPDATE & DRAW METHODS
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

int			MenuEvent::update(IScreen& screen, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		std::cout << "MenuEvent : Click !" << std::endl;
		for (std::vector<Button *>::const_iterator it = static_cast<MenuScreen *>(&screen)->getButtons().begin(); it != static_cast<MenuScreen *>(&screen)->getButtons().end(); ++it)
		{
			int statut = screen.getIndex();

			//Check for each button if the mouse click concern it
			if ((*it)->getColliders()[0]->getBoundingBox().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				if ((statut = (*it)->triggerEvent()) != screen.getIndex())
					return (statut);
		}
	default:
		break;
	}

	return (screen.getIndex());
}

void		MenuEvent::draw(IScreen& screen)
{
	for (std::vector<Button *>::const_iterator it = static_cast<MenuScreen *>(&screen)->getButtons().begin(); it != static_cast<MenuScreen *>(&screen)->getButtons().end(); ++it)
	{
		screen.getWindow().draw((*it)->getText());
		if (this->_toggle_bbox)
			showBoundingBoxes(static_cast<Entity&>(**it), screen.getWindow());
	}
}

int			GameEvent::update(IScreen& screen, sf::Event& event)
{
	return (screen.getIndex());
}


//OTHER METHODS
int			IEvent::changeScreen(int gamestate)
{
	return (gamestate);
}

int			MenuEvent::createGame(int gamestate, sf::RenderWindow* window)
{
	all_screens.push_back(new GameScreen(*window));
	return (gamestate);
}

void		MenuEvent::showBoundingBoxes(const Entity& e, sf::RenderWindow& window)
{
	const sf::Color type[4] = { sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::White };

	for (std::vector<BoxCollider *>::const_iterator it = e.getColliders().begin(); it != e.getColliders().end(); ++it)
	{
		sf::FloatRect	box = (*it)->getBoundingBox();
		sf::VertexArray lines(sf::LinesStrip, 5);

		lines[0].position = sf::Vector2f(box.left, box.top);
		lines[1].position = sf::Vector2f(box.left + box.width, box.top);
		lines[2].position = sf::Vector2f(box.left + box.width, box.top + box.height);
		lines[3].position = sf::Vector2f(box.left, box.top + box.height);
		lines[4].position = sf::Vector2f(box.left, box.top);
		for (unsigned int i = 0; i < lines.getVertexCount(); i++)
			lines[i].color = type[e.getType()];

		window.draw(lines);
	}
}

int			MenuEvent::toggleBoundingBoxes(int gamestate)
{
	this->_toggle_bbox = !this->_toggle_bbox;
	if (this->_toggle_bbox)
		std::cout << "Showing bounding boxes" << std::endl;
	else
		std::cout << "Hiding bounding boxes" << std::endl;
	return (gamestate);
}