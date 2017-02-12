#include "Event.h"
#include "Screen.h"
#include "Button.h"
#include "Collider.h"


//CONSTRUCTORS
IEvent::IEvent()
{
	std::cout << "Creating default options" << std::endl;
	this->_toggle_options.push_back(true); //Show bounding boxes
	this->_toggle_options.push_back(true); //Show grid
}

WindowDefaultEvent::WindowDefaultEvent()
{
	std::cout << "Creating window default event" << std::endl;
}

MenuEvent::MenuEvent()
{
	std::cout << "Creating menu event" << std::endl;
}

GameEvent::GameEvent()
{
	std::cout << "Creating game event" << std::endl;
}


//UPDATE & DRAW METHODS
int		WindowDefaultEvent::update(IScreen& screen, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		return (EXIT);
		break;
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			return (EXIT);
			break;
		default:
			break;
		}
	default:
		break;
	}

	return (screen.getIndex());
}

int		MenuEvent::update(IScreen& screen, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		std::cout << "MenuEvent : Click !" << std::endl;
		for (std::vector<Button *>::const_iterator it = static_cast<MenuScreen *>(&screen)->getButtons().begin(); it != static_cast<MenuScreen *>(&screen)->getButtons().end(); ++it)
		{
			int status = screen.getIndex();

			//Check for each button if the mouse click concern it
			for (std::vector<BoxCollider *>::const_iterator it2 = (*it)->getColliders().begin(); it2 != (*it)->getColliders().end(); ++it2)
			{
				if ((*it2)->getShape().getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					if ((status = (*it)->triggerEvent()) != screen.getIndex())
						return (status);
			}
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
		std::vector<sf::VertexArray>	boxes;

		screen.getWindow().draw((*it)->getText());
		if (this->_toggle_options[0])
		{
			this->getBoundingBoxes(static_cast<Entity<BoxCollider>&>(**it), boxes);
			for (std::vector<sf::VertexArray>::const_iterator it = boxes.begin(); it != boxes.end(); ++it)
				screen.getWindow().draw(*it);
		}
	}
}

int		GameEvent::update(IScreen& screen, sf::Event& event)
{
	GameScreen*	gscreen = static_cast<GameScreen *>(&screen);

	switch (event.type)
	{
	case sf::Event::MouseMoved:
		//Select a square on the grid according to mouse's position
		for (std::vector<std::vector<ParallelogramCollider *>>::iterator it = gscreen->getGrid().getSquares().begin(); it != gscreen->getGrid().getSquares().end(); ++it)
		{
			for (std::vector<ParallelogramCollider *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
			{
				if ((*it2)->contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)) && (*it2) != gscreen->getGrid().getSelectedSquare())
					gscreen->getGrid().selectSquare(**it2);
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		std::cout << "GameEvent : Click !" << std::endl;
		for (std::vector<Button *>::const_iterator it = gscreen->getButtons().begin(); it != gscreen->getButtons().end(); ++it)
		{
			int status = screen.getIndex();

			//Check for each button if the mouse click concern it
			for (std::vector<BoxCollider *>::const_iterator it2 = (*it)->getColliders().begin(); it2 != (*it)->getColliders().end(); ++it2)
			{
				if ((*it2)->getShape().getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					if ((status = (*it)->triggerEvent()) != screen.getIndex())
						return (status);
			}
		}

		//Here, perform operations when the player clicked on a case
		if (gscreen->getGrid().getSelectedSquare() != NULL)
		{
			sf::Vector2u	pos = gscreen->getGrid().getSquareIndex(gscreen->getGrid().getSelectedSquare());
			std::cout << "Clicked on case [" << pos.x << " ; " << pos.y << "]" << std::endl;

			gscreen->getGrid().setPlayerPosition(pos);
		}

	default:
		break;
	}

	return (screen.getIndex());
}

void		GameEvent::draw(IScreen& screen)
{
	GameScreen*	gscreen = static_cast<GameScreen *>(&screen);

	//Draw map
	gscreen->getWindow().draw(gscreen->getMap());

	//Draw grid
	if (this->_toggle_options[1])
	{
		ParallelogramCollider*	selected = gscreen->getGrid().getSelectedSquare();

		for (std::vector<sf::VertexArray>::const_iterator it = gscreen->getGrid().getLines().begin(); it != gscreen->getGrid().getLines().end(); ++it)
			gscreen->getWindow().draw(*it);
		if (selected != NULL)
		{
			selected->getShape().setFillColor(sf::Color(142, 200, 77));
			gscreen->getWindow().draw(selected->getShape());
		}
	}

	//Draw grid's entities
	for (std::vector<std::vector<Entity<BoxCollider> *>>::const_iterator it = gscreen->getGrid().getEntities().begin(); it != gscreen->getGrid().getEntities().end(); ++it)
	{
		for (std::vector<Entity<BoxCollider> *>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if ((*it2) != NULL)
			{
				gscreen->getWindow().draw((*it2)->getSprite());
				if (this->_toggle_options[0])
				{
					std::vector<sf::VertexArray>	boxes;

					this->getBoundingBoxes(**it2, boxes);
					for (std::vector<sf::VertexArray>::const_iterator it3 = boxes.begin(); it3 != boxes.end(); ++it3)
						gscreen->getWindow().draw(*it3);
				}
			}
		}
	}

	//Draw buttons
	for (std::vector<Button *>::const_iterator it = gscreen->getButtons().begin(); it != gscreen->getButtons().end(); ++it)
	{
		gscreen->getWindow().draw((*it)->getText());
		//Draw buttons's bounding boxes 
		if (this->_toggle_options[0])
		{
			std::vector<sf::VertexArray>	boxes;

			this->getBoundingBoxes(static_cast<Entity<BoxCollider>&>(**it), boxes);
			for (std::vector<sf::VertexArray>::const_iterator it = boxes.begin(); it != boxes.end(); ++it)
				gscreen->getWindow().draw(*it);
		}
	}
}


//GETTERS
bool	IEvent::getToggleBoundingBoxes()
{
	return (this->_toggle_options[0]);
}

bool	IEvent::getToggleGrid()
{
	return (this->_toggle_options[1]);
}

std::vector<bool>&	IEvent::getToggleOptions()
{
	return (this->_toggle_options);
}


//SETTERS
void	IEvent::setToggleOptions(const std::vector<bool>& toggle_options)
{
	this->_toggle_options = toggle_options;
}


//OTHER METHODS
int	IEvent::changeScreen(eGamestate gamestate, IScreen* screen)
{
	std::string	type[4] = { "menu", "options", "game" };
	int	index;

	if (gamestate == EXIT)
		return (gamestate);
	
	// Check if a screen with the gamestate passed as parameter already exist.
	// If true, copy options and return the gamestate.
	// Else, create the screen before performing operations.
	for (std::vector<IScreen *>::const_iterator it = all_screens.begin(); it != all_screens.end(); ++it)
	{
		if ((*it)->getState() == gamestate)
		{
			if ((*it)->getEvents()[1]->getToggleOptions() != this->_toggle_options)
			{
				std::cout << "Replacing old options" << std::endl;
				(*it)->getEvents()[1]->setToggleOptions(this->_toggle_options);
			}
			return ((*it)->getIndex());
		}
	}
	index = this->createScreen(gamestate, screen);
	std::cout << "Switching screen to " << type[(int)gamestate] << " at index " << index << "." << std::endl;
	return (index);
}

int	IEvent::createScreen(eGamestate gamestate, IScreen* screen)
{
	std::string	type[4] = { "menu", "options", "game" };
	IScreen*	new_screen;

	std::cout << std::endl << "Creating new " << type[(int)gamestate] << "." << std::endl;

	if (gamestate == MENU)
		new_screen = new MenuScreen(screen->getWindow());
	else if (gamestate == OPTIONS)
		new_screen = NULL;//new OptionsScreen(*window);
	else if (gamestate == GAME)
		new_screen = new GameScreen(screen->getWindow());
	new_screen->getEvents()[1]->setToggleOptions(this->_toggle_options);
	all_screens.push_back(new_screen);
	return (new_screen->getIndex());
}

int		IEvent::toggleBoundingBoxes(int index)
{
	this->_toggle_options[0] = !this->_toggle_options[0];
	if (this->_toggle_options[0])
		std::cout << "Showing bounding boxes" << std::endl;
	else
		std::cout << "Hiding bounding boxes" << std::endl;
	return (index);
}

int	IEvent::toggleGrid(int index)
{
	this->_toggle_options[1] = !this->_toggle_options[1];
	if (this->_toggle_options[1])
		std::cout << "Showing grid" << std::endl;
	else
		std::cout << "Hiding grid" << std::endl;
	return (index);
}