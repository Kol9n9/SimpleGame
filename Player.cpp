#include "Player.h"
void Player::InitVariables()
{
}
void Player::InitComponents()
{
	
}
//INITIALIZER FUNCTIONS
Player::Player(float x, float y, sf::Texture& TextureSheet)
{
	this->InitVariables();
	this->InitComponents();


	this->CreateMovementComponent(300.f, 10.f, 4.f);
	this->CreareAnimationComponent(TextureSheet);

	this->AnimationComponent->AddAnimation("IDLE", 5.f, 0, 0, 13, 0, 192, 192);
	this->AnimationComponent->AddAnimation("WALK_LEFT", 5.f, 0, 1, 11, 1, 192, 192);
}

Player::~Player()
{
}
void Player::Update(const float& dt)
{
	if (this->MovementComponent)
		this->MovementComponent->Update(dt);
	if (this->AnimationComponent)
	{
		if(this->MovementComponent->GetState(IDLE)) this->AnimationComponent->Play("IDLE", dt);
		else if(this->MovementComponent->GetState(MOVE_LEFT)) this->AnimationComponent->Play("WALK_LEFT", dt);
	}
}
//FUNCTIONS