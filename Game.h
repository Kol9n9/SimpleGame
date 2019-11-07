#pragma once
#ifndef GAME_H
#define GAME_H


#include "MainMenuState.h"
class Game
{
private:
	//Variables
	sf::RenderWindow* Window;
	sf::Event sfEvent;

	sf::Clock DTClock;
	float DT;

	std::stack<State*>states;
	std::map<std::string, int>SupportedKeys;
	std::vector<sf::VideoMode> VideoModes;
	sf::ContextSettings WindowSettings;
	bool Fullscreen;
	//Initialiser function
	void InitVariables();
	void InitWindow();
	void InitKeys();
	void InitStates();

public:
	//Constructor/desctructor
	Game();
	virtual ~Game();

	//Functions

	//regular
	void EndApplication();

	//update
	void UpdateDTClock();
	void UpdateSFMLEvents();
	void Update();
	//render
	void Render();
	//core
	void Run();

};

#endif // !GAME_H

