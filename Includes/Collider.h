#pragma once

/* A collider is a shape (rectangle, sphere, etc.) contained by an entity.
** When a collision occure, effects will vary depending on what the entity in cause should do. */

#include "SFML\Graphics.hpp"

class Entity;

class				BoxCollider
{
public:
	template <typename T> BoxCollider(const sf::Rect<T>& rect)
	{
		std::cout << "Add box collider at position [" << rect.left << " ; " << rect.top << "] and size [" << rect.width << " ; " << rect.height << "]." << std::endl;
		this->_box = static_cast<sf::FloatRect>(rect);
	};
	BoxCollider(float x, float y, int width, int height);
	template <typename T> BoxCollider(const sf::Vector2<T>& pos, const sf::Vector2<T>& size)
	{
		std::cout << "Add box collider at position [" << pos.x << " ; " << pos.y << "] and size [" << size.width << " ; " << size.height << "]." << std::endl;
		this->_box.left = pos.x;
		this->_box.top = pos.y;
		this->_box.width = size.x;
		this->_box.height = size.y;
	}

	virtual ~BoxCollider() {}

	//GETTERS
	sf::FloatRect&	getBoundingBox();

private:
	sf::FloatRect	_box;
};