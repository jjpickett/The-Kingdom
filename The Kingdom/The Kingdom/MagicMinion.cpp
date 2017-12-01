
#include "MagicMinion.h"
#include "Board.h"

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
	Minion* minion;
	switch (ability)
	{
	case'A': // Minions gain attack power
		for (int i = 0; i <= board->hostPlayersCardsInPlay.size(); i++)
			if (board->hostPlayersCardsInPlay.at(i)->getDamage() < amount)
				board->hostPlayersCardsInPlay.at(i)->setDamage(board->hostPlayersCardsInPlay.at(i)->getDamage() + amount);
		break;
	/*case'H': // Minions gain health points
		for (int i = 0; i <= board->hostPlayersCardsInPlay.size; i++)
			if (board->hostPlayersCardsInPlay.at(i)->getMaxHealth() - board->hostPlayersCardsInPlay.at(i)->getCurHealth() <= amount) 
				board->hostPlayersCardsInPlay.at(i)->setCurHealth(board->hostPlayersCardsInPlay.at(i)->getMaxHealth());
			else
				board->hostPlayersCardsInPlay.at(i)->setCurHealth(board->hostPlayersCardsInPlay.at(i)->getCurHealth + amount);
		break;*/
	case 'W': // Wake up friendly minions
		for (int i = 0; i < board->hostPlayersCardsInPlay.size(); i++)
		{
			minion = (Minion*)board->hostPlayersCardsInPlay.at(i);
			if (minion->isAsleep())
				minion->setAsleep(false);
		}
		break;
	}
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