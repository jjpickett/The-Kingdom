
#include "Magic.h"


Magic::Magic(GameDataRef data) : Card(data)
{
}

Magic::Magic(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount) : Card(data, name, description, cost)
{
	this->ability = ability;
	this->amount = amount;
}

Magic::~Magic()
{
}
