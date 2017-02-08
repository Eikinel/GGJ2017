#include "Entity.h"
#include "Collider.h"
#include "Button.h"

//SETTERS
/*void	Entity::setPosition(const sf::Vector2f& pos)
{
	
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
}*/