
#include "MagicPlayer.h"
#include "Board.h"

MagicPlayer::MagicPlayer(GameDataRef data) : Magic(data)
{
}

MagicPlayer::MagicPlayer(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount) : Magic(data, name, description, cost, ability, amount)
{
}

MagicPlayer::~MagicPlayer()
{
}

void MagicPlayer::effect(Board* board)
{
	switch (ability)
	{
	case'H':
		board->hostPlayer->setHealth(board->hostPlayer->getHealth() + amount);
		break;
	case'C':
		board->hostPlayer->setActionPoints(board->guestPlayer->getActionPoints() + amount);
		break;
	default:
		break;
	}
}

void MagicPlayer::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->endLine;
	Card::Init();
}

sf::Packet MagicPlayer::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount;
	return os;
}