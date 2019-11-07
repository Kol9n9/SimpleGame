#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponents.h"
#include "AnimationComponents.h"

class Entity
{
private:
	//INITIALIZER FUNCTIONS
	void InitVariables();
protected:
	sf::Sprite Sprite;
	MovementComponents* MovementComponent;
	AnimationComponents* AnimationComponent;
public:
	Entity();
	virtual ~Entity();
	//COMPONENT FUNCITONS
	void SpriteSetTexture(sf::Texture& Texture);
	void CreateMovementComponent(const float MaxSpeed, const float Acceleration, const float Deceleration);
	void CreareAnimationComponent(sf::Texture& TextureSheet);
	//FUNCTIONS
	virtual void SetPosition(const float x, const float y);	
	virtual void Move(const float DirX, const float DirY, const float& dt);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
	
};

#endif // !ENTITY_H