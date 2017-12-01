/// \file	MyPacket.h.
///
/// \brief	Declares my packet class

#pragma once

#include <SFML\Network.hpp>
#include <vector>
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include "Mage.h"
#include "Shaman.h"
#include "Warrior.h"

/// \class	MyPacket
///
/// \brief	my packet.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

class MyPacket : sf::Packet
{
public:

	/// \fn	MyPacket::MyPacket();
	///
	/// \brief	Default constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	MyPacket();

	/// \fn	MyPacket::~MyPacket();
	///
	/// \brief	Destructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	~MyPacket();

	/// \fn	sf::Packet MyPacket::sendCharacterPacket(Player *player);
	///
	/// \brief	Sends a character packet
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param [in,out]	player	If non-null, the player.
	///
	/// \return	A sf::Packet.

	sf::Packet sendCharacterPacket(Player *player);

	/// \fn	sf::Packet MyPacket::sendHandPacket(std::vector<Card *> cardsInHand);
	///
	/// \brief	Sends a hand packet
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param [in,out]	cardsInHand	If non-null, the cards in hand.
	///
	/// \return	A sf::Packet.

	sf::Packet sendHandPacket(std::vector<Card *> cardsInHand);

	/// \fn	sf::Packet MyPacket::sendPlayersCardsInPlay(std::vector<Card*> cardsInPlay);
	///
	/// \brief	Sends the cards that are in play on players side
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param [in,out]	cardsInPlay	If non-null, the cards in play.
	///
	/// \return	A sf::Packet.

	sf::Packet MyPacket::sendPlayersCardsInPlay(std::vector<Card*> cardsInPlay);

	/// \fn	sf::Packet MyPacket::sendOpponentsCardsInPlay(std::vector<Card*> cardsInPlay);
	///
	/// \brief	Sends the cards that are in play on players side
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param [in,out]	cardsInPlay	If non-null, the cards in play.
	///
	/// \return	A sf::Packet.

	sf::Packet MyPacket::sendOpponentsCardsInPlay(std::vector<Card*> cardsInPlay);

	/// \fn	std::vector<Card *> MyPacket::receiveOpponentInPlayPacket(sf::Packet packetReceive, GameDataRef data);
	///
	/// \brief	Recieves the opponents side of the board
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	packetReceive	The packet receive.
	/// \param	data		 	The data.
	///
	/// \return	Null if it fails, else a std::vector&lt;Card *&gt;

	std::vector<Card *> receiveOpponentInPlayPacket(sf::Packet packetReceive, GameDataRef data);

	/// \fn	std::vector<Card *> MyPacket::receivePlayerInPlayPacket(sf::Packet packetReceive, GameDataRef data);
	///
	/// \brief	Recieves how the opponent has damaged your side of the board
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	packetReceive	The packet receive.
	/// \param	data		 	The data.
	///
	/// \return	Null if it fails, else a std::vector&lt;Card *&gt;

	std::vector<Card *> receivePlayerInPlayPacket(sf::Packet packetReceive, GameDataRef data);

	/// \fn	sf::Packet MyPacket::sendTurn(bool isMyTurn);
	///
	/// \brief	Sends a turn
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	isMyTurn	True if this object is my turn.
	///
	/// \return	A sf::Packet.

	sf::Packet sendTurn(bool isMyTurn);

	/// \fn	Player* MyPacket::initOpponent(sf::Packet packetRecieve, GameDataRef data);
	///
	/// \brief	Initializes the opponent
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	packetRecieve	The packet recieve.
	/// \param	data		 	The data.
	///
	/// \return	Null if it fails, else a pointer to a Player.

	Player* initOpponent(sf::Packet packetRecieve, GameDataRef data);

	/// \fn	std::vector<sf::Sprite *> MyPacket::receiveHandPacket(sf::Packet packetReceive, GameDataRef data);
	///
	/// \brief	Receive hand packet
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	packetReceive	The packet receive.
	/// \param	data		 	The data.
	///
	/// \return	Null if it fails, else a std::vector&lt;sf::Sprite *&gt;

	std::vector<sf::Sprite *> receiveHandPacket(sf::Packet packetReceive, GameDataRef data);

	/// \fn	void MyPacket::receiveBoardPacket(sf::Packet packetRecieve);
	///
	/// \brief	Receive board packet
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	packetRecieve	The packet recieve.

	void receiveBoardPacket(sf::Packet packetRecieve);

	/// \fn	bool MyPacket::receiveTurnPacket(sf::Packet packetRecieve);
	///
	/// \brief	Receive turn packet
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	packetRecieve	The packet recieve.
	///
	/// \return	True if it succeeds, false if it fails.

	bool receiveTurnPacket(sf::Packet packetRecieve);

private:
	/// \brief	The packet send
	sf::Packet packetSend;
};

