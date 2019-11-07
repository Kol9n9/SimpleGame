#include "Game.h"
void Game::InitVariables()
{
	this->Window = NULL;
	this->Fullscreen = 0;
	this->DT = 0.f;
}
//Initialiser function
void Game::InitWindow()
{
	std::ifstream ifs("Config/window.ini");
	std::string title = "None";
	this->VideoModes = sf::VideoMode::getFullscreenModes();
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned framelimit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0;
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framelimit;
		ifs >> vertical_sync_enabled;
		ifs >> antialiasing_level;
	}
	ifs.close();
	
	this->WindowSettings.antialiasingLevel = antialiasing_level;
	this->Fullscreen = fullscreen;
	if(this->Fullscreen)
		this->Window = new sf::RenderWindow(window_bounds, title,sf::Style::Fullscreen ,this->WindowSettings);
	else
		this->Window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, this->WindowSettings);
	this->Window->setFramerateLimit(framelimit);
	this->Window->setVerticalSyncEnabled(vertical_sync_enabled);
}
void Game::InitKeys()
{

	std::ifstream ifs("Config/supported_keys.ini");
	if (ifs.is_open())
	{
		std::string Key = "";
		int KeyValue = 0;
		while (ifs >> Key >> KeyValue)
		{
			this->SupportedKeys[Key] = KeyValue;
		}
	}
	ifs.close();

}
void Game::InitStates()
{
	this->states.push(new MainMenuState(this->Window,&this->SupportedKeys,&this->states));
	//this->states.push(new GameState(this->Window,&this->SupportedKeys));
}
//Constructor/desctructor
Game::Game()
{
	this->InitVariables();
	this->InitWindow();
	this->InitKeys();
	this->InitStates();
}
Game::~Game()
{
	delete this->Window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}
//Functions
void Game::EndApplication()
{
}
void Game::UpdateDTClock()
{
	this->DT = this->DTClock.restart().asSeconds();
}

void Game::UpdateSFMLEvents()
{
	while (this->Window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{
			this->Window->close();
		}
	}
}

void Game::Update()
{
	this->UpdateSFMLEvents();
	if (!this->states.empty())
	{
		this->states.top()->Update(this->DT);
		if (this->states.top()->GetQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else
	{
		this->Window->close();
	}
}
void Game::Render()
{
	this->Window->clear();
	//Draw 
	if (!this->states.empty())
		this->states.top()->Render();

	this->Window->display();
}

void Game::Run()
{
	while (this->Window->isOpen())
	{
		this->UpdateDTClock();
		this->Update();
		this->Render();
	}

}

