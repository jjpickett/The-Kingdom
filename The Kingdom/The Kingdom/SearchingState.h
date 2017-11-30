#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "SFML\Network.hpp"
#include <iostream>

class SearchingState : public State
{
public:
	SearchingState(GameDataRef data);
	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	void LookForPlayer();

private:
	GameDataRef _data;

	sf::Sprite _background;

	sf::Sprite _cancelButton;


};

