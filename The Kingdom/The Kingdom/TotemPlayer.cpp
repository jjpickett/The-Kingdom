
#include "TotemPlayer.h"

TotemPlayer::TotemPlayer(GameDataRef data) : Totem(data)
{
}

TotemPlayer::TotemPlayer(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount, int health, bool taunt) : Totem(data, name, description, cost, ability, amount, health, taunt)
{
}

TotemPlayer::~TotemPlayer()
{
}

void TotemPlayer::effect(Board* board)
{
}

void TotemPlayer::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->curHealth >> this->taunt >> this->endLine;
	this->Init();
}

sf::Packet & TotemPlayer::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount << this->curHealth << this->taunt;
	return os;
}
