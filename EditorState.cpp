#include "EditorState.h"
void EditorState::InitVariables()
{


}

void EditorState::InitBackground()
{

}

void EditorState::InitKeybinds()
{
	std::ifstream ifs("Config/editor_keys.ini");
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

void EditorState::InitFonts()
{
	if (!this->Font.loadFromFile("Fonts/dosis-light.ttf"))
		throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
}

void EditorState::InitButtons()
{
	
}

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* SupportedKeys, std::stack<State*>* States)
	:State(window, SupportedKeys, States)
{
	this->InitVariables();
	this->InitBackground();
	this->InitFonts();
	this->InitKeybinds();
	this->InitButtons();

}

EditorState::~EditorState()
{
	/*for (auto it = this->Buttons.begin(); it != this->Buttons.end(); ++it)
	{
		delete it->second;
	}*/

}



void EditorState::UpdateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("CLOSE"))))
		this->EndState();
}

void EditorState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->RenderButtons(target);

	
}

void EditorState::RenderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->Buttons)
	{
		it.second->Render(target);
	}
}

void EditorState::Update(const float& dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(dt);
	this->UpdateButtons();


}

void EditorState::UpdateButtons()
{
	for (auto& it : this->Buttons)
	{
		it.second->Update(this->MousePosView);
	}

}
