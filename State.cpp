#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States)
{
	this->window = window;
	this->SupportedKeys = SupportedKeys;
	this->States = States;
	this->Quit = false;
}

State::~State()
{
}

const bool& State::GetQuit() const
{
	return this->Quit;
	// TODO: вставьте здесь оператор return
}

void State::EndState()
{
	this->Quit = true;
}

void State::UpdateMousePosition()
{
	this->MousePosScreen = sf::Mouse::getPosition();
	this->MousePosWindow = sf::Mouse::getPosition(*this->window);
	this->MousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
