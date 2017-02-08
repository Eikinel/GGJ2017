#pragma once

# include "Constants.h"
# include "Entity.h"

class	ParallelogramCollider;

class		Grid
{
public:
	Grid(const sf::Vector2u& win_size);
	~Grid();

	//GETTERS
	std::vector<std::vector<ParallelogramCollider *>>&	getSquares();
	std::vector<sf::VertexArray>&						getLines();
	virtual ParallelogramCollider*						getSelectedSquare();
	virtual const sf::Vector2u&							getSquareIndex(const ParallelogramCollider* square) const;

	//SETTERS
	virtual void	selectSquare(ParallelogramCollider& square);

private:
	std::vector<std::vector<ParallelogramCollider *>>	_squares;
	std::vector<sf::VertexArray>						_lines;
	ParallelogramCollider*								_selected;
};