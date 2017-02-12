#include "Player.h"


//CONSTRUCTORS
Player::Player(const sf::Vector2u& pos, const sf::FloatRect& square_side, const sf::Texture& texture) : Entity<BoxCollider>(PLAYER, texture)
{
	std::cout << "Creating new player" << std::endl;
	this->_pos = pos;

	this->_sprite.setScale(sf::Vector2f(
		square_side.height / this->_sprite.getGlobalBounds().height,
		square_side.height / this->_sprite.getGlobalBounds().height));
	this->setPosition(pos, square_side);
	this->addCollider(new BoxCollider(this->_sprite.getGlobalBounds(), BODY));
}

Player::Player(const sf::Vector2u& pos, const sf::FloatRect& square_side, const std::string& path_to_texture) : Entity<BoxCollider>(PLAYER, path_to_texture)
{
	std::cout << "Creating new player" << std::endl;
	this->_pos = pos;

	this->_sprite.setScale(sf::Vector2f(
		square_side.height / this->_sprite.getGlobalBounds().height,
		square_side.height / this->_sprite.getGlobalBounds().height));
	this->setPosition(pos, square_side);
	this->addCollider(new BoxCollider(this->_sprite.getGlobalBounds(), BODY));
}


//GETTERS
const sf::Vector2u&	Player::getPosition() const
{
	return (this->_pos);
}


//SETTERS
void	Player::setPosition(const sf::Vector2u& pos, const sf::FloatRect& square_side)
{
	std::cout << "Setting player position to [" << pos.x << " ; " << pos.y << "]" << std::endl;
	this->_pos = pos;
	this->_sprite.setPosition(sf::Vector2f(
		square_side.left + square_side.width / 4.f,
		square_side.top - square_side.height / 2.f));
	for (std::vector<BoxCollider *>::const_iterator it = this->_colliders.begin(); it != this->_colliders.end(); ++it)
		(*it)->getShape().setPosition(this->_sprite.getPosition());
}


//METHODS
void	Player::move(const sf::Vector2u& offset, const sf::FloatRect& square_side)
{
	this->setPosition(this->_pos + offset, square_side);
}