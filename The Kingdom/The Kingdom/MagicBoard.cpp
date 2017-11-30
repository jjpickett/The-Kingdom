
#include "MagicBoard.h"

MagicBoard::MagicBoard(GameDataRef data): Magic(data)
{
}

MagicBoard::MagicBoard(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount) : Magic(data, name, description, cost, ability, amount)
{
}

MagicBoard::~MagicBoard()
{
}

void MagicBoard::effect()
{
}

void MagicBoard::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->endLine;
	Card::Init();
}

sf::Packet MagicBoard::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount;
	return os;
}
