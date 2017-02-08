#pragma once

# include <SFML\Graphics.hpp>
# include <vector>
# include <iostream>

// Directories
# define ASSETS_DIR		"../Assets"
# define SPRITES_DIR	ASSETS_DIR"/Sprites"
# define FONTS_DIR		ASSETS_DIR"/Fonts"

// Global variable for screens, containing menu, game, etc.
class IScreen;
extern std::vector<IScreen *> all_screens;

// Static methods
static sf::Vector2f&	toIsometric(const sf::Vector2f& cart)
{
	float x, y;

	x = cart.x + cart.y / 2.f;
	y = cart.y;

	return (sf::Vector2f(x, y));
}

static sf::Vector2f&	toIsometric(const sf::FloatRect& cart)
{
	float x, y;

	x = cart.left + cart.top / 2.0f;
	y = cart.top;

	return (sf::Vector2f(x, y));
}

static sf::Vector2f&	toCartesian(const sf::Vector2f& iso)
{
	float x, y;

	x = (iso.x - iso.y) / 1.5;
	y = iso.y / 3.0 + iso.y / 1.5;

	return (sf::Vector2f(x, y));
}