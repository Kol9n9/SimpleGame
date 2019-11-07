#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include <iostream>
#include <string>

enum BTN_STATES {
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
};
class Button
{
private:
	unsigned short ButtonStates;
	unsigned CharacterSize;
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color IdleColor;
	sf::Color HoverColor;
	sf::Color ActiveColor;

	sf::Color IdleTextColor;
	sf::Color HoverTextColor;
	sf::Color ActiveTextColor;
public:
	Button(float x, float y, float width, float height, 
		sf::Font* font, std::string text, unsigned CharacterSize, sf::Color IdleTextColor, sf::Color HoverTextColor, sf::Color ActiveTextColor, 
		sf::Color IdleColor, sf::Color HoverColor, sf::Color ActiveColor);
	virtual ~Button();
	//Accesors
	const bool isPressed() const;
	//Functions
	void Update(const sf::Vector2f& MousePos);
	void Render(sf::RenderTarget* target);
};


#endif // !BUTTON_H