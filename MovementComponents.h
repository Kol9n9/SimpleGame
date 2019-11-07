#pragma once
#ifndef MOVEMENTCOMPONENTS_H
#define MOVEMENTCOMPONENTS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
enum MovementStates { IDLE = 0, MOVING, MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN };
class MovementComponents
{
private:
	//VARIABLES
	sf::Sprite& Sprite;
	float MaxVelocity;
	float Acceleration;
	float Deceleration;
	sf::Vector2f Velocity;

	//INITIALIZER FuNCTIONS
public:
	MovementComponents(sf::Sprite& Sprite, float MaxVelocity, float Acceleration, float Deceleration);
	virtual ~MovementComponents();
	//ACCESSORS
	const sf::Vector2f& GetVelocity() const;
	const bool GetState(const unsigned short State) const;
	
	//FUNCTIONS
	void Move(const float DirX, const float DirY, const float &dt);
	void Update(const float &dt);
};

#endif // !MOVEMENTCOMPONENTS_H