//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Nov 26, 2017
///
///
/// \brief The Board class contains all the players ands cards, controls the 
/// game logic and is used to update the players clients.
///

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include <iostream>
#include <algorithm>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Mage.h"
#include "Warrior.h"
#include "Shaman.h"
#include "MyPacket.h"

class Card;

// *******************************************************************************
/// \brief The Board class contains all the players ands cards, controls the 
/// game logic and is used to update the players clients.
// *******************************************************************************

class Board : public State
{
public:

	/// Creates the Board object and initializes it.
	/// \param[in] data The structure of game data.
	Board(GameDataRef data);

	/// Initializes the cards
	void Init();

	///  Controls whether a player can perform any actions.
	void HandleInput();

	///  receives a packet and updates the board based on the contents of the packet.
	void Update(float dt);

	/// Draws the background, the players and all the card textures.
	void Draw(float dt);

	/// Checks the win conditions to see if any player has less than 0 health points.
	void checkWinConditions();

	/// Checks whether a card has been destroyed or not.
	void checkDeath();

	/// Lets a Card attack another Card.
	/// \param[in] card1 The attacking Card.
	/// \param[in] card2 The Card being attacked.
	void attack(Card* card1, Card* card2);

	/// Cycles through all opponent's cards in play.
	/// \return If there are taunts on the board.
	bool checkTaunts();

	/// Updates the board and removes cards that have a health less than 0.
	void update();

	/// Ends the current players turn, locks their Cards, and then begins the
	/// turn for the next player and unlocks their Cards.
	void endTurn();
    
    /// The cards that the guestPlayer has in play.
	std::vector<Card*> guestPlayersCardsInPlay;

	/// The cards that the hostPlayer has in play.
	std::vector<Card*> hostPlayersCardsInPlay;

	/// The host player.
	Player* hostPlayer = NULL;

private:
	/// Game meta Data
	GameDataRef _data;

	///Textures that will be loaded for the background and border.
	sf::Sprite _background;
	sf::Sprite _border;

	/// True or false value used for verifying the turn order.
	bool hostPlayerTurn;

	/// Player attributes that will contain the guestPlayer.
	Player* guestPlayer = NULL;
	
	/// vector that contains the guestPlayers hand.
	std::vector<sf::Sprite*> guestPlayerInHand;

	/// Controls the game state.
	int gameState;

	///Msg that is sent alongside packet.
	std::string msgSend;

	/// Mutex to lock threads before sending packet.
	sf::Mutex globalMutex;
};
