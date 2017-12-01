
#include "TotemFriendly.h"

TotemFriendly::TotemFriendly(GameDataRef data) : Totem(data)
{
}

TotemFriendly::TotemFriendly(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount, int health, bool taunt) : Totem(data, name, description, cost, ability, amount, health, taunt)
{
}

TotemFriendly::~TotemFriendly()
{
}

void TotemFriendly::effect(Board* board)
{
}

void TotemFriendly::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->curHealth >> this->taunt >> this->endLine;
	this->Init();
}

sf::Packet TotemFriendly::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount << this->curHealth << this->taunt;
	return os;
}
