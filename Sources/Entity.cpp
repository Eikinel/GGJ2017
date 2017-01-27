#include "Entity.h"
#include "Collider.h"
#include "Button.h"

Entity::Entity(const eEntityType& type)
{
	this->_type = type;
}

Entity::Entity(const Entity& other)
{
	this->_colliders = other._colliders;
	this->_type = other._type;
}

Entity::~Entity()
{
	const std::string type[4] = {"button", "ally", "enemy", "object"};

	std::cout << "Deleting entity of type " << type[this->_type] << std::endl;
	for (std::vector<BoxCollider *>::const_iterator it = this->_colliders.begin(); it != this->_colliders.end(); ++it)
		delete(*it);
}


//GETTERS
const std::vector<BoxCollider *>&	Entity::getColliders() const
{
	return (this->_colliders);
}

const eEntityType&					Entity::getType() const
{
	return (this->_type);
}


//SETTERS
void	Entity::setPosition(const sf::Vector2f& pos)
{
	sf::FloatRect box;

	std::cout << "Moving entity of type " << this->_type << " to position [" << pos.x << " ; " << pos.y << "]." << std::endl;
	if (this->_type == BUTTON)
	{
		dynamic_cast<Button *>(this)->getText().setPosition(pos);
		box = dynamic_cast<Button *>(this)->getText().getGlobalBounds();
	}

	for (std::vector<BoxCollider *>::const_iterator it = this->_colliders.begin(); it != this->_colliders.end(); ++it)
	{
		(*it)->getBoundingBox().left = box.left;
		(*it)->getBoundingBox().top = box.top;
	}
}

void	Entity::setPosition(float x, float y)
{
	sf::FloatRect box;

	std::cout << "Moving entity of type " << this->_type << " to position [" << x << " ; " << y << "]." << std::endl;
	if (this->_type == BUTTON)
	{
		dynamic_cast<Button *>(this)->getText().setPosition(x, y);
		box = dynamic_cast<Button *>(this)->getText().getGlobalBounds();
	}

	for (std::vector<BoxCollider *>::const_iterator it = this->_colliders.begin(); it != this->_colliders.end(); ++it)
	{
		(*it)->getBoundingBox().left = box.left;
		(*it)->getBoundingBox().top = box.top;
	}
}


//METHODS
void	Entity::addCollider(BoxCollider* box_collider)
{
	this->_colliders.push_back(box_collider);
}