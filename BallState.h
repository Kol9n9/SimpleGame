#pragma once
#include "State.h"
class BallState :
	public State
{
private:
	sf::CircleShape Ball;
	sf::Vector2f Velocity;
	float Speed;
	int Radius;
	void InitVariables();
	void InitBall();
	void InitKeybinds();
public:
	BallState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States);
	virtual ~BallState();
	void UpdateInput(const float& dt);
	void Update(const float &dt);
	void UpdateBall(const float& dt);
	void Render(sf::RenderTarget *target = NULL);
};

