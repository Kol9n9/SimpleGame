#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	sf::Font* font, std::string text, unsigned CharacterSize, sf::Color IdleTextColor, sf::Color HoverTextColor, sf::Color ActiveTextColor,
	sf::Color IdleColor, sf::Color HoverColor, sf::Color ActiveColor)
{
	this->ButtonStates = BTN_IDLE;
	this->CharacterSize = CharacterSize;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(this->IdleTextColor);
	this->text.setCharacterSize(this->CharacterSize);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->IdleColor = IdleColor;
	this->HoverColor = HoverColor;
	this->ActiveColor = ActiveColor;

	this->IdleTextColor = IdleTextColor;
	this->HoverTextColor = HoverTextColor;
	this->ActiveTextColor = ActiveTextColor;

	this->shape.setFillColor(this->IdleColor);
}

Button::~Button()
{
}
// Accessors
const bool Button::isPressed() const
{
	if (this->ButtonStates == BTN_ACTIVE)
		return true;
	return false;
}
// Functions
void Button::Update(const sf::Vector2f& MousePos)
{
	/* Update the booleans for hover and pressed*/
	this->ButtonStates = BTN_IDLE;
	/* Hover button */
	if (this->shape.getGlobalBounds().contains(MousePos))
	{
		this->ButtonStates = BTN_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->ButtonStates = BTN_ACTIVE;
		}
	}
	switch (this->ButtonStates)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->IdleColor);
		this->text.setFillColor(this->IdleTextColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->HoverColor);
		this->text.setFillColor(this->HoverTextColor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->ActiveColor);
		this->text.setFillColor(this->ActiveTextColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::White);
		break;
	}
}

void Button::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
