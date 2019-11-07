#pragma once
#ifndef STATE_H
#define STATE_H


#include "Player.h"
class State
{
private:

protected:
	//Variables
	std::stack<State*>* States;
	sf::RenderWindow* window;
	std::map<std::string, int>* SupportedKeys;
	std::map<std::string, int> Keybinds;
	bool Quit;
	
	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;
	//Functions
	virtual void InitKeybinds() = 0;
	//Resources
	std::map<std::string, sf::Texture> Textures;
public:
	State(sf::RenderWindow* window,std::map<std::string,int>*SupportedKeys, std::stack<State*>* States);
	virtual ~State();

	const bool& GetQuit() const;

	void EndState();
	virtual void UpdateMousePosition();
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float &dt) = 0;
	virtual void Render(sf::RenderTarget * target = NULL) = 0;
};

#endif // !STATE_H