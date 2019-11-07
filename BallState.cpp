#include "BallState.h"

void BallState::InitVariables()
{
	this->Speed = 100;
	this->Radius = 50;
}

void BallState::InitBall()
{
	this->Ball.setFillColor(sf::Color::Green);
	this->Ball.setRadius(this->Radius);
}

void BallState::InitKeybinds()
{
	std::ifstream ifs("Config/keybinds_keys.ini");
	if (ifs.is_open())
	{
		std::string Key = "";
		std::string KeyValue = "";
		while (ifs >> Key >> KeyValue)
		{
			this->Keybinds[Key] = this->SupportedKeys->at(KeyValue);
		}
	}
	ifs.close();
}

BallState::BallState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States)
	:State(window,SupportedKeys,States)
{
	this->InitVariables();
	this->InitKeybinds();
	this->InitBall();
}

BallState::~BallState()
{
}

void BallState::UpdateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("CLOSE"))))
		this->EndState();
}

void BallState::Update(const float& dt)
{
	this->UpdateInput(dt);
	this->UpdateBall(dt);
}

void BallState::UpdateBall(const float& dt)
{
	std::cout << this->Ball.getPosition().x << " " << this->Ball.getPosition().y << "\n";
	

	this->Ball.move(this->Velocity * dt);
}

void BallState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->Ball);
}
