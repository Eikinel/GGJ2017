#pragma once

/* Everything is an entity, from living monster to background element.
** Entities are objects that are drawn onto the screen and can collide. */

# include "Constants.h"

enum			eEntityType
{
	BUTTON,
	PLAYER,
	ENEMY,
	GRID,
	OBJECT
};

template <typename T>
class			Entity
{
public:
	//CONSTRUCTORS
	Entity(const eEntityType& type, const sf::Texture& texture = sf::Texture())
	{
		this->_type = type;
		this->_texture = texture;
		this->_sprite.setTexture(this->_texture);
	}

	Entity(const eEntityType& type, const std::string& path_to_texture)
	{
		this->_type = type;
		if (this->_texture.loadFromFile(path_to_texture) == NULL)
			std::cout << "Failed to load " << path_to_texture << std::endl;
		this->_sprite.setTexture(this->_texture);
	}

	Entity(const Entity& other)
	{
		this->_colliders = other._colliders;
		this->_type = other._type;
		this->_texture = other._texture;
		this->_sprite = other._sprite;
	}

	virtual ~Entity()
	{
		const std::string type[5] = { "button", "hero", "enemy", "grid", "object" };

		std::cout << "Deleting entity of type " << type[this->_type] << std::endl;
		for (std::vector<T *>::const_iterator it = this->_colliders.begin(); it != this->_colliders.end(); ++it)
			delete(*it);
	}


	//GETTERS
	virtual sf::Sprite&				getSprite()
	{
		return (this->_sprite);
	}

	virtual const std::vector<T *>&	getColliders() const
	{
		return (this->_colliders);
	}

	virtual const eEntityType&		getType() const
	{
		return (this->_type);
	}


	//METHODS
	virtual void	addCollider(T * collider)
	{
		this->_colliders.push_back(collider);
	}

protected:
	sf::Texture			_texture;
	sf::Sprite			_sprite;
	std::vector<T *>	_colliders;
	eEntityType			_type;
};