#include "Grid.h"
#include "Collider.h"

//CONSTRUCTORS
Grid::Grid(const sf::Vector2u& win_size)
{
	unsigned int square_side = win_size.x / 33.f;
	int ct = 0;

	std::cout << "Creating new grid" << std::endl;
	for (float y = -(int)square_side; y < 2.f * win_size.y - square_side; y += square_side)
	{
		std::vector<ParallelogramCollider *> dummy;
		std::vector<Entity<BoxCollider> *>	null_entity;
		this->_squares.push_back(dummy);
		this->_entities.push_back(null_entity);

		for (float x = -ct * (int)square_side; x < -ct * (int)square_side + (int)win_size.x; x += square_side)
		{
			this->_squares[ct].push_back(new ParallelogramCollider(x, y, square_side, square_side, CASE));
			this->_entities[ct].push_back(NULL);

			sf::FloatRect	box(x, y, square_side, square_side);
			sf::VertexArray	lines(sf::LinesStrip, 5);

			lines[0].position = toIsometric(sf::Vector2f(box.left, box.top));
			lines[1].position = toIsometric(sf::Vector2f(box.left + box.width, box.top));
			lines[2].position = toIsometric(sf::Vector2f(box.left + box.width, box.top + box.height));
			lines[3].position = toIsometric(sf::Vector2f(box.left, box.top + box.height));
			lines[4].position = toIsometric(sf::Vector2f(box.left, box.top));

			for (unsigned int i = 0; i < lines.getVertexCount(); i++)
				lines[i].color = sf::Color(255, 255, 255, 33);
			this->_lines.push_back(lines);
		}
		ct++;
	}

	this->_selected = NULL;
}

Grid::~Grid()
{
	std::cout << "Deleting grid" << std::endl;
	for (std::vector<std::vector<ParallelogramCollider *>>::const_iterator it = this->_squares.begin(); it != this->_squares.end(); ++it)
		for (std::vector<ParallelogramCollider *>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			sf::Vector2u	pos = this->getSquareIndex(*it2);

			std::cout << "Deleting case [" << pos.x << " ; " << pos.y << "]" << std::endl;
			delete(*it2);
			if (this->_entities[pos.y][pos.x] != NULL) // Delete entities on grid
				delete(this->_entities[pos.y][pos.x]);
		}
}


//GETTERS
std::vector<std::vector<ParallelogramCollider *>>&	Grid::getSquares()
{
	return (this->_squares);
}

std::vector<sf::VertexArray>&	Grid::getLines()
{
	return (this->_lines);
}

ParallelogramCollider*			Grid::getSelectedSquare()
{
	return (this->_selected);
}

const sf::Vector2u&				Grid::getSquareIndex(const ParallelogramCollider* square) const
{
	sf::Vector2u	pos;

	for (unsigned int y = 0; y < this->_squares.size(); y++)
		for (unsigned int x = 0; x < this->_squares[y].size(); x++)
			if (this->_squares[y][x] == square)
				pos = sf::Vector2u(x, y);

	return (pos);
}

Player&		Grid::getPlayer()
{
	for (std::vector<std::vector<Entity<BoxCollider> *>>::const_iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
		for (std::vector<Entity<BoxCollider> *>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
			if (*it2 != NULL && (*it2)->getType() == PLAYER)
				return (*dynamic_cast<Player *>(*it2));
}

const std::vector<std::vector<Entity<BoxCollider> *>>&	Grid::getEntities() const
{
	return (this->_entities);
}


//SETTERS
void		Grid::selectSquare(ParallelogramCollider& square)
{
	this->_selected = &square;
}

void		Grid::addPlayer(Player* player)
{
	sf::Vector2u	pos = player->getPosition();
	
	std::cout << "Adding player to the grid" << std::endl;
	this->_entities[pos.y][pos.x] = player;
}

void	Grid::setPlayerPosition(const sf::Vector2u& pos)
{
	sf::Vector2u old_pos = this->getPlayer().getPosition();

	this->getPlayer().setPosition(pos, this->_squares[pos.y][pos.x]->getShape().getGlobalBounds());
	this->_entities[pos.y][pos.x] = &this->getPlayer();
	this->_entities[old_pos.y][old_pos.x] = NULL;
}


//METHODS
void	Grid::movePlayer(const sf::Vector2u& offset)
{
	this->setPlayerPosition(this->getPlayer().getPosition() + offset);
}