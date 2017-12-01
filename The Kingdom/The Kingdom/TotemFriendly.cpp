
#include "TotemFriendly.h"
#include "Board.h"
#include <stdio.h>

TotemFriendly::TotemFriendly(GameDataRef data) : Totem(data)
{
}

TotemFriendly::TotemFriendly(GameDataRef data, std::string name, std::string description, int cost, char ability, bool taunt, int health, int amount) : Totem(data, name, description, cost, ability, taunt, health, amount)
{
}

TotemFriendly::~TotemFriendly()
{
}

void TotemFriendly::effect(Board* board)
{
    std::cout << "Ability: |" << ability << "|";
    switch (ability)
    {
        case 'H':
            for (int i = 0; i < board->hostPlayersCardsInPlay.size(); i++)
            {
                if (board->hostPlayersCardsInPlay.at(i)->getId() != TOTEM_FRIENDLY_CARD)
                board->hostPlayersCardsInPlay.at(i)->setCurHealth(1);
            }
            break;
        /*case 'A':
            Minion *tempMinion;
            for (int i = 0; i < board->hostPlayersCardsInPlay.size(); i++)
            {
                if (board->hostPlayersCardsInPlay.at(i)->getId() == MINION_CARD ||
                    board->hostPlayersCardsInPlay.at(i)->getId() == MINION_TAUNT_CARD ||
                    board->hostPlayersCardsInPlay.at(i)->getId() == MINION_BATTLECRY_CARD)
                {
                    tempMinion = dynamic_cast<Minion*>(board->hostPlayersCardsInPlay.at(i));
                  //  tempMinion.ac
                 //    board->hostPlayersCardsInPlay.at(i)->action(1);
                }
            }
            break;*/
    }
}

void TotemFriendly::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->curHealth >> this->taunt >> this->endLine;
	this->Init();
}

sf::Packet & TotemFriendly::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount << this->curHealth << this->taunt;
	return os;
}
