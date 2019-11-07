#pragma once
#ifndef ANIMATIONCOMPONENTS_H
#define ANIMATIONCOMPONENTS_H
#include <iostream>
#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class AnimationComponents
{
private:
	class Animation {
	public:
		sf::Texture& TextureSheet;
		sf::Sprite& Sprite;
		float AnimationTimer;
		float Timer;
		int Height;
		int Width;
		sf::IntRect StartRect;
		sf::IntRect EndRect;
		sf::IntRect CurrentRect;
		Animation(sf::Sprite &Sprite, sf::Texture& TextureSheet, float AnimationTimer, int StartFrameX, int StartFrameY, int EndFrameX, int EndFrameY, int Width, int Height)
			: Sprite(Sprite), TextureSheet(TextureSheet), AnimationTimer(AnimationTimer), Width(Width), Height(Height)
		{
			this->Timer = 0;
			this->StartRect = sf::IntRect(StartFrameX*this->Width, StartFrameY*this->Height, this->Width, this->Height);
			this->EndRect = sf::IntRect(EndFrameX*this->Width, EndFrameY*this->Height, this->Width, this->Height);
			this->CurrentRect = this->StartRect;
			this->Sprite.setTexture(this->TextureSheet);
			this->Sprite.setTextureRect(this->StartRect);
		}
		//Function
		void Play(const float &dt)
		{
			this->Timer += 100.f * dt;
			if (this->Timer >= this->AnimationTimer)
			{
				this->Timer = 0;
				if (this->CurrentRect != this->EndRect)
					this->CurrentRect.left += this->Width;
				else this->CurrentRect.left = this->StartRect.left;
				this->Sprite.setTextureRect(this->CurrentRect);
			}
		}
		void Pause();
		void Reset();
	};
	//VARIABLES
	std::map<std::string, Animation*> AnimationList;
	sf::Sprite& Sprite;
	sf::Texture& TextureSheet;
	//INITIALIZER FUNCTIONS
public:
	AnimationComponents(sf::Sprite& Sprite, sf::Texture& TextureSheet);
	virtual ~AnimationComponents();
	//FUNCTIONS
	void AddAnimation(const std::string key, float AnimationTimer, int StartFrameX, int StartFrameY, int EndFrameX, int EndFrameY, int Width, int Height);
	void Play(const std::string key, const float& dt);
};

#endif // !ANIMATIONCOMPONENTS_H