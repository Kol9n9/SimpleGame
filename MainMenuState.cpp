#include "MainMenuState.h"

void MainMenuState::InitVariables()
{
	

}

void MainMenuState::InitBackground()
{
	this->Background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x), 
			static_cast<float>(this->window->getSize().y)
		)
	);
	if (!this->BackgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD BACKGROUND");
	this->Background.setTexture(&this->BackgroundTexture);
}

void MainMenuState::InitKeybinds()
{
	std::ifstream ifs("Config/mainmenu_keys.ini");
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

void MainMenuState::InitFonts()
{
	if (!this->Font.loadFromFile("Fonts/dosis-light.ttf"))
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
}

void MainMenuState::InitButtons()
{
	this->Buttons["GAME_STATE"] = new Button(
		300.f, 480.f, 250.f, 50.f, 
		&this->Font, "New Game", 30, 
		sf::Color(70, 70, 70, 200), sf::Color(250,250,250,250), sf::Color(20,20,20,50), 
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->Buttons["SETTINGS_STATE"] = new Button(
		300.f, 540.f, 250.f, 50.f,
		&this->Font, "Settings", 30,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->Buttons["EDITOR_STATE"] = new Button(
		300.f, 600.f, 250.f, 50.f,
		&this->Font, "Editor", 30,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->Buttons["BALL_STATE"] = new Button(
		300.f, 660.f, 250.f, 50.f,
		&this->Font, "Ball play", 30,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->Buttons["EXIT"] = new Button(
		300.f, 740.f, 250.f, 50.f,
		&this->Font, "Exit", 25,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States)
	:State(window, SupportedKeys,States)
{
	this->InitVariables();
	this->InitBackground();
	this->InitFonts();
	this->InitKeybinds();
	this->InitButtons();

}

MainMenuState::~MainMenuState()
{
	for (auto it = this->Buttons.begin(); it != this->Buttons.end(); ++it)
	{
		delete it->second;
	}
	 
}



void MainMenuState::UpdateInput(const float& dt)
{
}

void MainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->Background);
	this->RenderButtons(target);

	//REMOVE LATER
	sf::Text TextMouse;
	TextMouse.setPosition(this->MousePosView);
	TextMouse.setFont(this->Font);
	TextMouse.setCharacterSize(12);
	std::stringstream ss;
	ss << "\n" << this->MousePosView.x << " | " << this->MousePosView.y << "\n";
	TextMouse.setString(ss.str());
	target->draw(TextMouse);
}

void MainMenuState::RenderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->Buttons)
	{
		it.second->Render(target);
	}
}

void MainMenuState::Update(const float& dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(dt);
	this->UpdateButtons();
	
	
}

void MainMenuState::UpdateButtons()
{
	for (auto& it : this->Buttons)
	{
		it.second->Update(this->MousePosView);
	}
	if(this->Buttons["GAME_STATE"]->isPressed())
	{
		this->States->push(new GameState(this->window, this->SupportedKeys, this->States));
	}
	if (this->Buttons["BALL_STATE"]->isPressed())
	{
		this->States->push(new BallState(this->window, this->SupportedKeys, this->States));
	}
	if (this->Buttons["EXIT"]->isPressed())
	{
		this->Quit = true;
	}
}
