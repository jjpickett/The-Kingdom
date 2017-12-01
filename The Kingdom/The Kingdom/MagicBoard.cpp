
#include "MagicBoard.h"
#include "Board.h"
#include "Minion.h"

MagicBoard::MagicBoard(GameDataRef data) : Magic(data)
{
}

MagicBoard::MagicBoard(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount) : Magic(data, name, description, cost, ability, amount)
{
}

MagicBoard::~MagicBoard()
{
}

void MagicBoard::effect(Board* board)
{
	Minion* minion = 0;
	Totem* totem = 0;
	switch (ability)
	{
	case 'G': // Removes all taunts on the board
		if (board->checkTaunts())
			for (int i = 0; i < board->guestPlayersCardsInPlay.size() && board->checkTaunts(); i++)
				if (board->guestPlayersCardsInPlay.at(i)->getId() == MINION_TAUNT_CARD)
				{
					minion = (Minion*)board->guestPlayersCardsInPlay.at(i);
					minion->setTaunt(false);
				}
				else if (board->guestPlayersCardsInPlay.at(i)->getId() == TOTEM_TAUNT_CARD)
				{
					totem = (Totem*)board->guestPlayersCardsInPlay.at(i);
					totem->setTaunt(false);
				}
		break;
	/*case 'H':
		for (int i = 0; i < board->hostPlayersCardsInPlay.size(); i++) 
			if ((board->hostPlayersCardsInPlay.at(i)->getMaxHealth() - board->hostPlayersCardsInPlay.at(i)->getCurHealth()) <= this->amount)
				board->hostPlayersCardsInPlay.at(i)->setCurHealth(board->hostPlayersCardsInPlay.at(i)->getMaxHealth());
		break;*/
	case 'D': // Damages all opponent cards
		for (int i = 0; i < board->guestPlayersCardsInPlay.size(); i++)
			board->guestPlayersCardsInPlay.at(i)->setCurHealth(-amount);
		break;
	default:
		break;
	}
	delete minion;
	delete totem;
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
