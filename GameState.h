#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class GameState :
	public State
{
private:
	Player* player;
	//INITIALIZER FUNCTIONS
	void InitKeybinds();
	void InitTextures();
	void InitPlayers();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States);
	virtual ~GameState();

	//FUNCTIONS
	void UpdateInput(const float& dt);
	void Render(sf::RenderTarget* target = NULL);
	void Update(const float& dt);
};

#endif // !GAMESTATE_H