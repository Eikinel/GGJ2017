#include "Grid.h"
#include "Collider.h"

//CONSTRUCTORS
Grid::Grid(const sf::Vector2u& win_size)
{
	unsigned int square_side = win_size.x / 20.f;

	std::cout << "Creating new grid" << std::endl;
	for (float y = 0; y < win_size.y; y += square_side)
	{
		std::vector<ParallelogramCollider *> dummy;
		this->_squares.push_back(dummy);

		for (float x = ((-1) * (float)square_side) * ((float)win_size.y / (float)square_side); x < (float)win_size.x; x += square_side)
		{
			this->_squares[y / square_side].push_back(new ParallelogramCollider(x, y, square_side, square_side, CASE));

			sf::FloatRect	box(x, y, square_side, square_side);
			sf::VertexArray	lines(sf::LinesStrip, 5);

			lines[0].position = toIsometric(sf::Vector2f(box.left, box.top));
			lines[1].position = toIsometric(sf::Vector2f(box.left + box.width, box.top));
			lines[2].position = toIsometric(sf::Vector2f(box.left + box.width, box.top + box.height));
			lines[3].position = toIsometric(sf::Vector2f(box.left, box.top + box.height));
			lines[4].position = toIsometric(sf::Vector2f(box.left, box.top));

			for (unsigned int i = 0; i < lines.getVertexCount(); i++)
				lines[i].color = sf::Color(142, 142, 142);
			this->_lines.push_back(lines);
		}
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


//SETTERS
void		Grid::selectSquare(ParallelogramCollider& square)
{
	this->_selected = &square;
}