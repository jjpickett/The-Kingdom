//#pragma once

#include "MinionBattleCry.h"
#include "Board.h"

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

sf::Packet & MinionBattleCry::write(sf::Packet & os)
{
	os << this->getId() << this->getName() << this->description << this->cost << this->curHealth << this->damageValue << this->taunt << this->charge << this->ability << this->amount;
	return os;
}

void MinionBattleCry::effect(Board* board)
{
    if (board->guestPlayersCardsInPlay.size() != 0)
    {
        switch (ability)
        {
            case 'R':
                if (amount == 1)
                {
                    int randomNum = rand() % board->guestPlayersCardsInPlay.size();

                    board->guestPlayersCardsInPlay.erase(board->guestPlayersCardsInPlay.begin() + randomNum);
                }
                else if (amount == 2)
                {
                    int randomNum = rand() % board->guestPlayersCardsInPlay.size();
                    int randomNum2 = rand() % board->guestPlayersCardsInPlay.size() - 1;

                    board->guestPlayersCardsInPlay.erase(board->guestPlayersCardsInPlay.begin() + randomNum);
                    board->guestPlayersCardsInPlay.erase(board->guestPlayersCardsInPlay.begin() + randomNum2);

                    // ***** TODO: Show changes for both players when card is played ***** //
                }
                break;
            case 'D':
                for (int i = 0; i < board->guestPlayersCardsInPlay.size(); i++)
                {
                    if (amount == 1)
                    {
                        board->guestPlayersCardsInPlay.at(i)->setCurHealth(-1);
                    }
                    else if (amount == 2)
                    {
                        board->guestPlayersCardsInPlay.at(i)->setCurHealth(-2);
                    }
                }
                break;
            /*
            case 'W':
                Minion *tempMinion;
                for (int i = 0; i < board->hostPlayersCardsInPlay.size(); i++)
                {
                    if (board->hostPlayersCardsInPlay.at(i)->getId() == MINION_CARD ||
                        board->hostPlayersCardsInPlay.at(i)->getId() == MINION_TAUNT_CARD ||
                        board->hostPlayersCardsInPlay.at(i)->getId() == MINION_BATTLECRY_CARD)
                    {
                        tempMinion = dynamic_cast<Minion*>(board->hostPlayersCardsInPlay.at(i));
                        tempMinion->setSleep(false);
                        tempMinion->Draw();
                        //tempMinion->asleepText.setString(asleep ? "" : "");
                        board->hostPlayersCardsInPlay.at(i) = tempMinion;
                    }
                }
                break;
                */
        }
    }
    
}