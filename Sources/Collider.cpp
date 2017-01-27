#include "Collider.h"
#include "Entity.h"

//CONSTRUCTORS
BoxCollider::BoxCollider(float x, float y, int width, int height)
{
	std::cout << "Add box collider at position [" << x << " ; " << y << "] and size [" << width << " ; " << height << "]." << std::endl;
	this->_box.left = x;
	this->_box.top = y;
	this->_box.width = width;
	this->_box.height = height;
}


//GETTERS
sf::FloatRect&	BoxCollider::getBoundingBox()
{
	return (this->_box);
}