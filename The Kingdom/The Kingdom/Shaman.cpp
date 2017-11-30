
#include "Shaman.h"


Shaman::Shaman()
{
}

Shaman::Shaman(GameDataRef data)
{
	this->_data = data;
	this->_playerSprite.setTexture(_data->assets.getTexture("Shaman"));
}

Shaman::~Shaman()
{
}

void Shaman::effect(Board * board)
{
}