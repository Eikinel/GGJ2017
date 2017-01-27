#include "Button.h"
#include "Collider.h"


//CONSTRUCTORS
Button::Button(const std::string& text, const size_t& size, const sf::Vector2f& pos, const eIndent indent, const std::string& path) : Entity(BUTTON)
{
	std::string	format[3] = { "LEFT", "CENTER", "RIGHT" };

	std::cout << "Add button with text \"" << text << "\"." << std::endl;
	this->_font.loadFromFile(path);
	this->_text.setString(text);
	this->_text.setFont(this->_font);
	this->_text.setCharacterSize(size);
	this->_text.setOrigin(sf::Vector2f(
		(this->_text.getGlobalBounds().width / 2.f) * (float)indent,
		this->_text.getGlobalBounds().height / 2.f));
	std::cout << "Position avant " << format[indent] << " : " << pos.x << " ; " << pos.y << "." << std::endl;
	std::cout << "Position apres " << format[indent] << " : " << pos.x + (pos.x / 2.f) * ((float)indent - 1.f) << " ; " << pos.y << "." << std::endl;
	this->_text.setPosition(pos + sf::Vector2f(
		(pos.x / 2.f) * ((float)indent - 1.f), 0));
	this->_event = NULL;
	this->addCollider(new BoxCollider(this->_text.getGlobalBounds()));
}

Button::Button(const std::string& text, const size_t& size, const sf::Font& font, const sf::Vector2f& pos, const eIndent indent) : Entity(BUTTON)
{
	std::cout << "Add button with text \"" << text << "\"." << std::endl;
	this->_font = font;
	this->_text.setString(text);
	this->_text.setFont(this->_font);
	this->_text.setCharacterSize(size);
	this->_text.setOrigin(sf::Vector2f(
		(this->_text.getGlobalBounds().width / 2.f) * (float)indent,
		this->_text.getGlobalBounds().height / 2.f));
	this->_text.setPosition(pos);
	this->_event = NULL;

	sf::FloatRect	box = this->_text.getGlobalBounds();

	this->addCollider(new BoxCollider(box));
}

Button::Button(const Button& other) : Entity(other._type)
{
	std::cout << "Copy button with text \"" << this->_text.getString().toAnsiString() << "\"." << std::endl;
	this->_font = other._font;
	this->_text = other._text;
	this->_colliders = other._colliders;
	this->_event = other._event;
}

Button::~Button()
{
}


//GETTERS
sf::Text&	Button::getText() 
{
	return (this->_text);
}

const std::function<int()>&	Button::getEvent()
{
	return (this->_event);
}


//METHODS
int		Button::triggerEvent()
{
	if (this->_event != NULL)
		return(this->_event());
}