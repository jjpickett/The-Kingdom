
#include "MinionFriendly.h"
#include "Board.h"

MinionFriendly::MinionFriendly(GameDataRef data) : Minion(data)
{
}

MinionFriendly::MinionFriendly(GameDataRef data, std::string name, std::string description, int cost, int health, int attack, bool taunt, bool charge, char ability, int amount) : Minion(data, name, description, cost, health, attack, taunt, charge)
{
	this->ability = ability;
	this->amount = amount;
}

MinionFriendly::~MinionFriendly()
{
}

void MinionFriendly::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->curHealth >> this->damageValue >> this->taunt >> this->charge >> this->ability >> this->amount >> this->endLine;
	this->Init();

}

sf::Packet MinionFriendly::write(sf::Packet & os)
{
	os << this->getId() << this->getName() << this->description << this->cost << this->curHealth << this->damageValue << this->taunt << this->charge << this->ability << this->amount;
	return os;
}

void MinionFriendly::effect(Board* board)
{
    char test = ability;
    int randomNum = 0;
    switch (ability)
    {
        case 'H':
            randomNum = rand() % board->hostPlayersCardsInPlay.size();
            board->hostPlayersCardsInPlay.at(randomNum)->setCurHealth(+1);
        break;
        case 'P':
            for (int i = 0; i < board->guestPlayersCardsInPlay.size(); i++)
            {
                board->guestPlayersCardsInPlay.at(i)->setCurHealth(-1);
                
            }
        break;
    }
}