#pragma once

# include "Constants.h"
# include "Entity.h"
# include <functional>

class IEvent;

enum			eIndent
{
	LEFT = 0,
	CENTER,
	RIGHT
};

class			Button : public Entity
{
public:
	Button(const std::string& text, const size_t& size, const sf::Vector2f& pos = sf::Vector2f(0, 0), const eIndent indent = LEFT, const std::string& path_to_font = FONTS_DIR"/moyko.ttf");
	Button(const std::string& text, const size_t& size, const sf::Font& font, const sf::Vector2f& pos = sf::Vector2f(0, 0), const eIndent indent = LEFT);
	Button(const Button& other);
	virtual ~Button();

	//GETTERS
	virtual sf::Text&					getText();
	virtual const std::function<int()>&	getEvent();

	//SETTERS
	template <typename U, typename... T> void onClick(int (U::*func)(T...), U* event, T... params)
	{
		this->_event = std::bind(func, event, params...);
	}
	template <typename U, typename V, typename... T> void onClick(int (U::*func)(T..., V), U* event, V params2, T... params)
	{
		this->_event = std::bind(func, event, params2, params...);
	}

	//METHODS
	int triggerEvent();

private:
	sf::Font				_font;
	sf::Text				_text;
	std::function<int()>	_event;
};