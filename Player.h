#pragma once
#ifndef PLAYER_H
#define PLAYER_H


#include "Entity.h"
class Player :
	public Entity
{
private:
	//VARIABLES
	//INITIALIZER FUNCTIONS
	void InitVariables();
	void InitComponents();
public:
	Player(float x, float y, sf::Texture& TextureSheet);
	virtual ~Player();
	//FUNCTIONS
	void Update(const float& dt);
};

#endif // !PLAYER_H