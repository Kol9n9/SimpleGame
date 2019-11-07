#include "MovementComponents.h"
//INITIALIZER FuNCTIONS
MovementComponents::MovementComponents(sf::Sprite& Sprite, float MaxVelocity, float Acceleration, float Deceleration)
	:Sprite(Sprite), MaxVelocity(MaxVelocity), Acceleration(Acceleration), Deceleration(Deceleration)
{
	
}

MovementComponents::~MovementComponents()
{
}
//ACCESSORS
const sf::Vector2f& MovementComponents::GetVelocity() const
{
	return this->Velocity;
}
const bool MovementComponents::GetState(const unsigned short State) const
{
	switch (State)
	{
	case IDLE:
		if (this->Velocity.x == 0 && this->Velocity.y == 0)
			return true;
		break;
	case MOVING:
		if (this->Velocity.x != 0 || this->Velocity.y != 0)
			return true;
		break;
	case MOVE_LEFT:
		if (this->Velocity.x < 0.f)
			return true;
		break;
	case MOVE_RIGHT:
		if (this->Velocity.x > 0.f)
			return true;
		break;
	case MOVE_UP:
		if (this->Velocity.y < 0.f)
			return true;
		break;
	case MOVE_DOWN:
		if (this->Velocity.y > 0.f)
			return true;
		break;
	default:
		break;
	}
	return false;
}
//FUNCTIONS
void MovementComponents::Move(const float DirX, const float DirY, const float &dt)
{
	//Accelaration
	this->Velocity.x += this->Acceleration * DirX;	 
	this->Velocity.y += this->Acceleration * DirY;
	
	
}

void MovementComponents::Update(const float& dt)
{
	//Decelaration
	if (this->Velocity.x > 0.f) // Right
	{
		if (this->Velocity.x > this->MaxVelocity)
			this->Velocity.x = this->MaxVelocity;

		//DECELERATION x positive

		this->Velocity.x -= this->Deceleration;
		if (this->Velocity.x < 0.f)
			this->Velocity.x = 0.f;

	}
	else if (this->Velocity.x < 0.f) // Left
	{
		if (this->Velocity.x < -this->MaxVelocity)
			this->Velocity.x = -this->MaxVelocity;

		this->Velocity.x += this->Deceleration;
		if (this->Velocity.x > 0.f)
			this->Velocity.x = 0.f;
	}
	if (this->Velocity.y > 0.f) // Down
	{
		if (this->Velocity.y > this->MaxVelocity)
			this->Velocity.y = this->MaxVelocity;

		this->Velocity.y -= this->Deceleration;
		if (this->Velocity.y < 0.f)
			this->Velocity.y = 0.f;
	}
	else if (this->Velocity.y < 0.f) // Up
	{
		if (this->Velocity.y < -this->MaxVelocity)
			this->Velocity.y = -this->MaxVelocity;

		this->Velocity.y += this->Deceleration;
		if (this->Velocity.y > 0.f)
			this->Velocity.y = 0.f;
	}
	std::cout << "Velocity: " << this->Velocity.x << " - " << this->Velocity.y << "\n";
	//Final
	this->Sprite.move(this->Velocity * dt);
}
