
#include "Warrior.h"

Warrior::Warrior( )
{
}

Warrior::Warrior(GameDataRef data)
{
	this->_data = data;
	_playerSprite.setTexture(_data->assets.getTexture("Warrior"));
}


Warrior::~Warrior()
{
}

void Warrior::effect(Board * board)
{
}

