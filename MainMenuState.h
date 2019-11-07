#pragma once
#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "GameState.h"
#include "BallState.h"
#include "Button.h"
class MainMenuState :
	public State
{
private:
	//VARIABLES
	sf::Texture BackgroundTexture;
	sf::RectangleShape Background;
	sf::Font Font;
	std::map <std::string, Button*> Buttons;
	//Initilisation
	void InitVariables();
	void InitBackground();
	void InitKeybinds();
	void InitFonts();
	void InitButtons();
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States);
	virtual ~MainMenuState();

	
	void UpdateInput(const float& dt);
	void Render(sf::RenderTarget* target = NULL);
	void RenderButtons(sf::RenderTarget* target = NULL);
	void Update(const float& dt);
	void UpdateButtons();
};
#endif // !MAINMENUSTATE_H
