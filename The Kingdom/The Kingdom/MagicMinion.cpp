
#include "MagicMinion.h"

MagicMinion::MagicMinion(GameDataRef data) : Magic(data)
{
}

MagicMinion::MagicMinion(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount) : Magic(data, name, description, cost, ability, amount)
{
}

MagicMinion::~MagicMinion()
{
}

void MagicMinion::effect(Board* board)
{
}

void MagicMinion::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->endLine;
	Card::Init();
}

sf::Packet MagicMinion::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount;
	return os;
}