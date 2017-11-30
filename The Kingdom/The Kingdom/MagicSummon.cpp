
#include "MagicSummon.h"

MagicSummon::MagicSummon(GameDataRef data) : Magic(data)
{
}

MagicSummon::MagicSummon(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount) : Magic(data, name, description, cost, ability, amount)
{
}

MagicSummon::~MagicSummon()
{
}

void MagicSummon::effect()
{
}

void MagicSummon::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->endLine;
	Card::Init();
}

sf::Packet MagicSummon::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount;
	return os;
}
