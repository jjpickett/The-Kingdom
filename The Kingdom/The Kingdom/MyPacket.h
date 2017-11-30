#pragma once

#include <SFML\Network.hpp>
#include <vector>
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include "Mage.h"
#include "Shaman.h"
#include "Warrior.h"
class MyPacket : sf::Packet
{
public:
	MyPacket();
	~MyPacket();
	sf::Packet sendCharacterPacket(Player *player);
	sf::Packet sendHandPacket(std::vector<Card *> cardsInHand);
	
	//Sends the cards that are in play on players side
	sf::Packet MyPacket::sendPlayersCardsInPlay(std::vector<Card*> cardsInPlay);
	//Sends the cards that are in play on players side
	sf::Packet MyPacket::sendOpponentsCardsInPlay(std::vector<Card*> cardsInPlay);

	//Recieves the opponents side of the board
	std::vector<Card *> receiveOpponentInPlayPacket(sf::Packet packetReceive, GameDataRef data);

	//Recieves how the opponent has damaged your side of the board
	std::vector<Card *> receivePlayerInPlayPacket(sf::Packet packetReceive, GameDataRef data);
	
	sf::Packet sendTurn(bool isMyTurn);

	Player* initOpponent(sf::Packet packetRecieve, GameDataRef data);
	std::vector<sf::Sprite *> receiveHandPacket(sf::Packet packetReceive, GameDataRef data);
	void receiveBoardPacket(sf::Packet packetRecieve);
	bool receiveTurnPacket(sf::Packet packetRecieve);

private:
	sf::Packet packetSend;
};

