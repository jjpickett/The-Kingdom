
#include "MinionBattleCry.h"


MinionBattleCry::MinionBattleCry(GameDataRef data) : Minion(data)
{
}

MinionBattleCry::MinionBattleCry(GameDataRef data, std::string name, std::string description, int cost, int health, int attack, bool taunt, bool charge, char ability, int amount) : Minion(data, name, description, cost, health, attack, taunt, charge)
{
	this->ability = ability;
	this->amount = amount;

}


MinionBattleCry::~MinionBattleCry()
{
}

void MinionBattleCry::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->curHealth >> this->damageValue >> this->taunt >> this->charge >> this->ability >> this->amount >> this->endLine;
	this->Init();
}

sf::Packet MinionBattleCry::write(sf::Packet & os)
{
	os << this->getId() << this->getName() << this->description << this->cost << this->curHealth << this->damageValue << this->taunt << this->charge << this->ability << this->amount;
	return os;
}

void MinionBattleCry::effect()
{
}