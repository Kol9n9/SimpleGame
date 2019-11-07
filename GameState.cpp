#include "GameState.h"
//INITIALIZER FUNCTIONS
void GameState::InitKeybinds()
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

void GameState::InitTextures()
{
	if (!this->Textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/PLAYER_SHEET.png"))
		throw ("ERROR::GAMESTATE::COULD NOT LOAD TEXTURE");
}

void GameState::InitPlayers()
{
	this->player = new Player(0, 0, this->Textures["PLAYER_SHEET"]);
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys,std::stack<State*>* States)
	:State(window,SupportedKeys,States)
{
	this->InitKeybinds();
	this->InitTextures();
	this->InitPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

//FUNCTIONS
void GameState::UpdateInput(const float& dt)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("MOVE_LEFT")))) 
		this->player->Move(-1.f, 0.f,dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("MOVE_RIGHT"))))
		this->player->Move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("MOVE_UP"))))
		this->player->Move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("MOVE_DOWN"))))
		this->player->Move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("CLOSE"))))
		this->EndState();
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	this->player->Render(target);
}

void GameState::Update(const float& dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(dt);
	
	this->player->Update(dt);
}
