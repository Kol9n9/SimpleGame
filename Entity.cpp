#include "Entity.h"
//INITIALIZER FUNCTIONS
void Entity::InitVariables()
{
	this->MovementComponent = NULL;
	this->AnimationComponent = NULL;
}

Entity::Entity()
{
	this->InitVariables();
}

Entity::~Entity()
{
	delete this->MovementComponent;
	delete this->AnimationComponent;
}
//COMPONENT FUNCITONS
void Entity::SpriteSetTexture(sf::Texture& Texture)
{
	this->Sprite.setTexture(Texture);
	
}

void Entity::CreateMovementComponent(const float MaxSpeed, const float Acceleration, const float Deceleration)
{
	this->MovementComponent = new MovementComponents(this->Sprite,MaxSpeed,Acceleration,Deceleration);
	
}

void Entity::CreareAnimationComponent(sf::Texture& TextureSheet)
{
	this->AnimationComponent = new AnimationComponents(this->Sprite, TextureSheet);
}

//FUNCTIONS
void Entity::SetPosition(const float x, const float y)
{
	this->Sprite.setPosition(x, y);
}
void Entity::Move(const float DirX, const float DirY, const float& dt)
{
	if (this->MovementComponent)
	{ 
		this->MovementComponent->Move(DirX, DirY,dt);
	}
}

void Entity::Update(const float& dt)
{
	
}

void Entity::Render(sf::RenderTarget* target)
{
	target->draw(this->Sprite);
}
