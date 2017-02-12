#pragma once

# include "Constants.h"
# include "Player.h"

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

	virtual Player&		getPlayer();
	virtual const std::vector<std::vector<Entity<BoxCollider> *>>&	getEntities() const;

	//SETTERS
	virtual void	selectSquare(ParallelogramCollider& square);
	virtual void	addPlayer(Player* entity);
	virtual void	setPlayerPosition(const sf::Vector2u& pos);

	//METHODS
	virtual void	movePlayer(const sf::Vector2u& offset);

private:
	//Grid components
	std::vector<std::vector<ParallelogramCollider *>>	_squares;
	std::vector<sf::VertexArray>						_lines;
	ParallelogramCollider*								_selected;

	//Entities on grid
	std::vector<std::vector<Entity<BoxCollider> *>>		_entities;
};