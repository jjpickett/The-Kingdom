#pragma once
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"

class GameOverState : public State
{
public:
	GameOverState(GameDataRef data);
	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;

	sf::Sprite _background;

	sf::Sprite _returnButton;

};

