#pragma once

/* Everything is an entity, from living monster to background element.
** Entities are objects that are drawn onto the screen and can collide. */

#include "Constants.h"

class BoxCollider;

enum			eEntityType
{
	BUTTON,
	ALLY,
	ENEMY,
	OBJECT
};

class			Entity
{
public:
	Entity(const eEntityType& type);
	Entity(const Entity& other);
	virtual ~Entity();

	//GETTERS
	virtual const std::vector<BoxCollider *>&	getColliders() const;
	virtual const eEntityType&					getType() const;

	//SETTERS
	virtual void	setPosition(const sf::Vector2f& pos);
	virtual void	setPosition(float x, float y);

	//METHODS
	virtual void	addCollider(BoxCollider* box_collider);

protected:
	std::vector<BoxCollider *>	_colliders;
	eEntityType					_type;
};