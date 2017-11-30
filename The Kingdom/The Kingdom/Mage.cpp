
#include "Mage.h"


Mage::Mage()
{
}

Mage::Mage(GameDataRef data)
{	
	this->_data = data;
	this->_playerSprite.setTexture(_data->assets.getTexture("Mage"));
}



Mage::~Mage()
{
}

void Mage::effect()
{
}
