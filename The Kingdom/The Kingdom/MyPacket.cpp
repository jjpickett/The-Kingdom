
#include "MyPacket.h"
#include "CardFactory.h"
#include "Mage.h"
#include "Shaman.h"
#include "Warrior.h"
#include <iostream>

MyPacket::MyPacket()
{
}


MyPacket::~MyPacket()
{
}

sf::Packet MyPacket::sendCharacterPacket(Player * player)
{
	packetSend.clear();

	return sf::Packet();
}

sf::Packet MyPacket::sendHandPacket(std::vector<Card*> cardsInHand)
{
	packetSend.clear();
	packetSend << 1;
	sf::Uint32 x = cardsInHand.size();
	packetSend << x;
	return packetSend;
}

sf::Packet MyPacket::sendPlayersCardsInPlay(std::vector<Card*> cardsInPlay)
{
	packetSend.clear();
	packetSend << 2;
	packetSend << cardsInPlay.size();

	for(int i = 0; i < cardsInPlay.size(); i++)
		packetSend << cardsInPlay.at(i)->write(packetSend);

	return packetSend;
}

sf::Packet MyPacket::sendOpponentsCardsInPlay(std::vector<Card*> cardsInPlay)
{
	packetSend.clear();
	packetSend << 3;
	

	for (int i = 0; i < cardsInPlay.size(); i++)
		packetSend << cardsInPlay.at(i)->write(packetSend);


	packetSend << static_cast<sf::Uint32>(cardsInPlay.size());
	for (std::vector<Card*>::const_iterator it = cardsInPlay.begin(); it != cardsInPlay.end(); ++it)
		packetSend << *it;

	return packetSend;
}

std::vector<Card*> MyPacket::receiveOpponentInPlayPacket(sf::Packet packetReceive, GameDataRef data)
{
	CardFactory cardFactory;
	
	return cardFactory.newCard(data, packetReceive);
}



std::vector<Card*> MyPacket::receivePlayerInPlayPacket(sf::Packet packetReceive, GameDataRef data)
{
	CardFactory cardFactory;

	return cardFactory.newCard(data, packetReceive);
}



sf::Packet MyPacket::sendTurn(bool isMyTurn)
{
	packetSend.clear();
	std::cout << "Waiting for opponents turn to end...";
	return packetSend << 4 << isMyTurn;
}

Player* MyPacket::initOpponent(sf::Packet packetRecieve, GameDataRef data)
{
	int temp;
	packetRecieve >> temp;
	if (temp == MAGE_CHARACTER)
		return new Mage(data);
	else if (temp == SHAMAN_CHARACTER)
		return new Shaman(data);
	else if (temp == WARRIOR_CHARACTER)
		return  new Warrior(data);
}

std::vector<sf::Sprite*> MyPacket::receiveHandPacket(sf::Packet packetReceive, GameDataRef data)
{
	sf::Uint32 size = 0;
	packetReceive >> size;
	std::vector<sf::Sprite *> cardVectorPlayer;
	for (sf::Uint32 i = 0; i < size; ++i)
	{
		//TODO: ADJUST THIS
		sf::Sprite *item = new sf::Sprite();
		item->setTexture(data->assets.getTexture("CardBack"));
		cardVectorPlayer.push_back(item);
	}
	return cardVectorPlayer;
}

void MyPacket::receiveBoardPacket(sf::Packet packetRecieve)
{
}

bool MyPacket::receiveTurnPacket(sf::Packet packetRecieve)
{
	bool temp;
	packetRecieve >> temp;
	std::cout << "My Turn...";
	return temp;
}