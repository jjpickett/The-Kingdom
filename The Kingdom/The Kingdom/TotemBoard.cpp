
#include "TotemBoard.h"
#include "Board.h"

TotemBoard::TotemBoard(GameDataRef data) : Totem(data)
{
}

TotemBoard::TotemBoard(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount, int health, bool taunt) : Totem(data, name, description, cost, ability, amount, health, taunt)
{
}

TotemBoard::~TotemBoard()
{
}

void TotemBoard::effect(Board* board)
{
	switch (ability)
	{
	case 'D': // Damages all opponent cards
		for (int i = 0; i < board->guestPlayersCardsInPlay.size(); i++)
			board->guestPlayersCardsInPlay.at(i)->setCurHealth(-amount);
		break;
	}
}

void TotemBoard::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->curHealth >> this->taunt >> this->endLine;
	this->Init();
}

sf::Packet TotemBoard::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount << this->curHealth << this->taunt;
	return os;
}
