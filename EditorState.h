#pragma once
#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "Button.h"
class EditorState :
	public State
{
private:
	//VARIABLES

	sf::Font Font;
	std::map <std::string, Button*> Buttons;
	//Initilisation
	void InitVariables();
	void InitBackground();
	void InitKeybinds();
	void InitFonts();
	void InitButtons();
public:
	EditorState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States);
	virtual ~EditorState();


	void UpdateInput(const float& dt);
	void Render(sf::RenderTarget* target = NULL);
	void RenderButtons(sf::RenderTarget* target = NULL);
	void Update(const float& dt);
	void UpdateButtons();
};

#endif