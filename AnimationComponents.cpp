#include "AnimationComponents.h"

AnimationComponents::AnimationComponents(sf::Sprite& Sprite, sf::Texture& TextureSheet)
	:Sprite(Sprite), TextureSheet(TextureSheet)
{
}

AnimationComponents::~AnimationComponents()
{
	for (auto& i : this->AnimationList)
		delete i.second;
}

void AnimationComponents::AddAnimation(const std::string key, float AnimationTimer, int StartFrameX, int StartFrameY, int EndFrameX, int EndFrameY, int Width, int Height)
{
	this->AnimationList[key] = new Animation(this->Sprite, this->TextureSheet, AnimationTimer, StartFrameX, StartFrameY, EndFrameX, EndFrameY, Width, Height);
}

void AnimationComponents::Play(const std::string key, const float& dt)
{
	this->AnimationList[key]->Play(dt);
}
