#pragma once

# include "Entity.h"
# include "Collider.h"

class			Player : public Entity<BoxCollider>
{
public:
	Player(const sf::Vector2u& pos, const sf::FloatRect& square_side, const sf::Texture& texture);
	Player(const sf::Vector2u& pos, const sf::FloatRect& square_side, const std::string& path_to_texture);
	~Player() {	std::cout << "Deleting player" << std::endl; }

	//GETTERS
	virtual const sf::Vector2u&	getPosition() const;

	//SETTERS
	virtual void	setPosition(const sf::Vector2u& pos, const sf::FloatRect& square_side);

	//METHODS
	virtual void	move(const sf::Vector2u& offset, const sf::FloatRect& square_side);

private:
	sf::Vector2u	_pos;
};